// PROBLEM: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// Given an array of integers nums and an integer k. A continuous subarray is called nice 
// if there are k odd numbers on it.
// Return the number of nice sub-arrays.


#include<bits/stdc++.h>
using namespace std;


// =============================== Approach 1(Reducing to SubarraySumEqualsK problem) ===============
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    // Replace all odd numbers with 1 and even numbers with 0
    for(auto &it: nums){
        if(it&1){
            it = 1;
        }
        else{
            it = 0;
        }
    }

    // Now the problem is reduced to:
    // Find number of subarrays with sum = K

    int pre_sum = 0;
    int count=0;

    unordered_map<int, int> mp;
    mp[0]=1;

    for(auto it: nums){
        pre_sum+= it;

        if(mp.count(pre_sum-k)){
            // AB = x and AC = x-k => BC = k
            // if there exists n subarrays with prefix sum = sum-k at a pt
            // it means there exists n subarrays with sum = k till that pt
            // Hence, we add the count of subarrays with preSum = preSum-k
            // to the total count
            count+= mp[pre_sum-k];
        }

        mp[pre_sum]++;
    }

    return count;
}

// =============== Approach 2: Using same concept as above without modification ====================
int numberOfSubarrays(vector<int>& nums, int k) {
    int count=0;
    int oddCount=0;
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]&1){
            oddCount++;
        }

        if(oddCount==k){
            count++;
        }

        if(mp.find(oddCount-k)!=mp.end()){
            count+=mp[oddCount-k];
        }

        mp[oddCount]++;
    }

    return count;
}

int main()
{
    return 0;
}