// PROBLEM: https://leetcode.com/problems/subarray-sum-equals-k/
// Given an array of integers nums and an integer k, 
// return the total number of subarrays whose sum equals to k.

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int pre_sum = 0;
    int count=0;

    unordered_map<int, int> mp;
    mp[0]=1; // very important

    for(auto it: nums){
        pre_sum+= it;

        if(mp.count(pre_sum-k)){
            // AB = x and AC = x-k => BC = k
            // That means, if there exists n subarrays with prefix sum = sum-k at a pt
            // it means there exists n subarrays with sum = k till that pt
            // Hence, we add the count of subarrays with preSum = preSum-k
            // to the total count
            count+= mp[pre_sum-k];
        }

        mp[pre_sum]++;
    }

    return count;

}

int main()
{
    return 0;
}