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
    if (currIdx == nums.size())
    {
        return 0;
    }
    if (t[currIdx][prevIdx + 1] != -1)
    {
        // since we cannot store prevIdx = -1 in dp as we cannot have negative index
        // therefore, we coordinate shift each index by one position to right 
        // i.e. store prevIdx at position prevIdx+1
        return t[currIdx][prevIdx + 1];
    }

    int notPick = helper(nums, currIdx + 1, prevIdx);
    if (prevIdx == -1 || nums[currIdx] > nums[prevIdx])
    {
        int pick = 1 + helper(nums, currIdx + 1, currIdx);
        return t[currIdx][prevIdx + 1] = max(pick, notPick);
    }
    else
    {
        return t[currIdx][prevIdx + 1] = notPick;
    }
}


int lengthOfLIS(vector<int> &nums)
{
    int currIdx = 0;
    int prevIdx = -1;
    t.resize(nums.size(), vector<int>(nums.size() + 1, -1)); 
    // here size of dp is [n][n+1] as prev moves from -1 till n-1

    return helper(nums, currIdx, prevIdx);
}


// **************** Using Tabulation ***********************
// int lengthOfLIS(vector<int> &nums){
//     vector<vector<int>> t(nums.size(), vector<int>(nums.size() + 1, -1)); 
//      for(int i=0; i<=nums.size(); i++){
//         for(int j=0; j<=nums.size()+1; j++){
//             if(i==nums.size()) return 0;
//         }
//     }

//     for(int i=0; i<nums.size(); i++){
//         for(int j=0; j<=nums.size()+1; j++){
//             int notPick = t[i+1][j];
//             if (j == -1 || nums[i] > nums[j])
//             {
//                 int pick = 1 + t[i+1][i];
//                 t[i][j + 1] = max(pick, notPick);
//             }
//             else
//             {
//                 t[i][j + 1] = notPick;
//             }
//         }
//     }

//     return t[nums.size()][nums.size()+1];
// }


// **************** M3: Using Binary Search & LB/UB ********************

// INTUITION: 
// Since, we are concerned only with the length of longest increasing subsequence,
// therefore, we can iterate through the array and for every element, we can replace the 
// lower bound(which gives index of arr[i] if exists or index of first element > arr[i]) 
// of that element in existing sequence with the element itself

int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            *it = nums[i];
        }
    }
    return temp.size();
}


int main()
{
    return 0;
}