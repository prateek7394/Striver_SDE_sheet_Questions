// QUESTION:
// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that 
// the maximum difference amongst all the pairs is minimized. 
// Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|,
// where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

#include<bits/stdc++.h>
using namespace std;

//  EXPLAINATION:
//  Form sets containing p pairs as many as possible
//  For every pair in each set, find the abs diff of the elements in each pair
//  Find the maximum diff amongst p pairs in each set
//  Return the min. value out of these maximum differences.

bool PairsFound(int diff, vector<int> nums, int p){
    int i=1;
    int count=0;
    while(i<nums.size()){
        if(nums[i]-nums[i-1]<=diff){
            count++;
            i+=2;
        }
        else{
            i++;
        }
    }
    return count>=p;
}

int minimizeMax(vector<int>& nums, int p) {
    int n = nums.size();
    sort(begin(nums), end(nums));

    int low = 0; // minimum possible diff when two elements are equal
    int high = nums[n-1]-nums[0]; // maximum possible diff since array is sorted
    
    int ans = 0;
    // We can linearly search for availability of p pairs from low till high
    // but that would be more time consuming.
    // So, we apply Binary search on ans

    while(low<=high){
        int diff = (low+high)/2;
        if(PairsFound(diff, nums, p)){
            // check whether we can get p pairs each having difference of elements <=diff
            // (here we check for <=  because this diff is max diff for every set containing p pairs)
            // If found, then this diff can be a potential ans 
            ans = diff;
            high = diff-1; 
            // To search for some smaller possible diff for which we can get
            // p pairs, we move high pointer before mid
        }
        else{
            // If p pairs not found for this diff, we increase the diff by
            // moving the low pointer
            low = diff+1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}