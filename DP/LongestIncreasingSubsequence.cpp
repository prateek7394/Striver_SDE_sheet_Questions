// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include <bits/stdc++.h>
using namespace std;

// ***************************** Using Memoization *********************
// T.C = O(n*n) --> evaluate each cell in dp we make n*n recursive calls
// S.C = O(n*n) --> size of dp
// A.S = O(n) for recursion space stack

vector<vector<int>> t;
int helper(vector<int> &nums, int currIdx, int prevIdx)
{
    // NOTE: helper(3, 0) gives the length of LIS starting from 3rd index whose prevIdx is 0
    if (currIdx == nums.size())
    {
        // no elements remaining
        return 0;
    }
    if (t[currIdx][prevIdx + 1] != -1)
    {
        // since we cannot store prevIdx = -1 in dp as we cannot have negative index
        // therefore, we coordinate shift each index by one position to right
        // i.e. store prevIdx at position prevIdx+1
        return t[currIdx][prevIdx + 1];
    }

    int notPick = 0 + helper(nums, currIdx + 1, prevIdx); // no increase in length
    if (prevIdx == -1 || nums[currIdx] > nums[prevIdx])
    {
        int pick = 1 + helper(nums, currIdx + 1, currIdx); // length increases by 1
        return t[currIdx][prevIdx + 1] = max(pick, notPick);
    }
    else
    {
        return t[currIdx][prevIdx + 1] = notPick;
    }
}


int lengthOfLIS1(vector<int> &nums)
{
    int currIdx = 0; // stores the index of current element
    int prevIdx = -1; // stores the index of last element that we added in our subsequence
    t.resize(nums.size(), vector<int>(nums.size() + 1, -1)); 
    // here size of dp is [n][n+1] as prev moves from -1 till n-1

    return helper(nums, currIdx, prevIdx);
}


// **************** Method 2: Using 1d DP ***********************
int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[j]<nums[i]){
                dp[i] =  max(dp[i], 1+dp[j]);
                // here we used the pre computed value for longest increasing subarray till jth index
                // we keep updating value of dp[i] for each value of dp[j] so that it remains maximum
                // adding 1 means we are including curr element
            }
        }
        ans = max(ans, dp[i]); // update the global ans storing the length of LIS
    }
    for(auto it: dp){
        cout<< it<<" ";
    }
    return ans;
}


// **************** M3: Using Binary Search & Lower Bound ********************

// INTUITION: 
// Since, we are concerned only with the length of longest increasing subsequence,
// therefore, we can iterate through the array and for every element, we can replace the 
// lower bound(which gives index of arr[i] if exists or index of first element > arr[i]) 
// of that element in existing sequence with the element itself.

// NOTE: Here temp does not give the correct elements in LIS, it only gives the length of LIS

int lengthOfLIS3(vector<int>& nums) {
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++){
        if(nums[i]>temp.back()){ // If curr element is greater than the last element in LIS, add it.
            temp.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]); 
            // find the place in LIS where curr Element can fit and replace that position with curr Element
            // This saves space of creating a new subseq at every junction as we are making changes in same subseq
            *it = nums[i];
        }
    }
    return temp.size();
}


int main()
{
    vector<int> arr = {1, 3, 5, 4, 7};
    int ans = lengthOfLIS2(arr);
    
    return 0;
}