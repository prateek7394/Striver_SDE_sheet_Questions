// PROBLEM: https://leetcode.com/problems/house-robber/description/

#include<bits/stdc++.h>
using namespace std;

// ---------------- M1(Using Memoization) ------------------

class Solution {
public:
    vector<int>dp;
    int helper(int idx, vector<int> &arr){
        if(idx>=arr.size()){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        // pick
        int pick = arr[idx]+ helper(idx+2, arr);
        
        // not pick
        int notPick = helper(idx+1, arr);
        
        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return helper(0, nums);
    }
};

// ------------------------------ M2(Using Tabulation) ----------------------

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp = nums;
        dp[1] = max(nums[0], nums[1]);

        // Here, dp[i] denotes maximum loot that we can get by considering till ith index.

        for(int i=2; i<n; i++){
            // we have two options:
            // either rob current house and add its loot to the total loot till (i-2)
            // or skip current house and loot remains same as till (i-1)
            
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp.back();
    }
};

// ------------------------ M3(Space Optimisation) --------------------

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=0, prev2=0, curr=0;

        for(auto it: nums){
            curr = max(it+prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};

int main()
{
    return 0;
}