// PROBLEM: https://leetcode.com/problems/subarray-sum-equals-k/


// APPROACH:
// If till a point the prefixSum is x and we have n subarrays with prefixSum=(x-k) in hash map till that point
// => we have n subarrays with prefixSum = k till that point.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp; // {sum, count of subarrays with given sum}
        int preSum=0;

        for(int i=0; i<nums.size(); i++){
            preSum+= nums[i];

            if(preSum==k){
                count++;
            }

            if(mp.count(preSum-k)){
                count+=mp[preSum-k];
            }

            mp[preSum]++;
        }

        return count;
    }
};

// ------------------------- M2(Striver's Method) ----------------------

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp; // {sum, count of subarrays with given sum}
        mp[0]=1; 
        // store this in map to satisfy the condition when preSum itself equals to k. Then we look for elements with preSum=0
        // i.e. we have 1 subarray i.e. the current subarray. So, increase count by 1.
        int preSum=0;

        for(int i=0; i<nums.size(); i++){
            preSum+= nums[i];
            count+=mp[preSum-k]; 
            mp[preSum]++;
        }

        return count;
    }
};

int main()
{
    return 0;
}