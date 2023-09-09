// PROBLEM: https://leetcode.com/problems/combination-sum-iv/description

// Given an array of distinct integers nums and a target integer target, 
// return the number of possible combinations that add up to target.
// Note that different sequences are counted as different combinations. E.g. {1,1,2}, {1,2,1} and {2,1,1} 
// are all different combinations.

#include<bits/stdc++.h>
using namespace std;

int t[1001];

int helper(vector<int>& nums, int target){
    if(target==0){
        return 1;
    }

    if(t[target]!=-1){
        return t[target];
    }

    int ans=0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]<=target)
            ans += helper(nums, target-nums[i]);
    }

    return t[target] = ans;
}

int combinationSum4(vector<int>& nums, int target) {
    memset(t, -1, sizeof(t));
    return helper(nums, target);
}

int main()
{
    return 0;
}
