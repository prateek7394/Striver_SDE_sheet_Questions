// PROBLEM : https://leetcode.com/problems/house-robber-ii/




#include<bits/stdc++.h>
using namespace std;

// ------------------------------ Method 1 -------------------------
class Solution {
public:
    int helper(vector<int>&arr){
        int n = arr.size();
        if(n==1){
            return arr[0];
        }

        vector<int>dp(n+1);
        dp[0]=arr[0];
        dp[1]=max(arr[0], arr[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }

        if(n==1){
            return nums[0];
        }

        // In this case, we have 2 choices:
        // either choose first house and leave the last house or
        // choose the last house and leave the first house

        vector<int>nums1(nums.begin(), nums.end()-1);  // leave the last house
        vector<int>nums2(nums.begin()+1, nums.end()); // leave the first house
        int val1 = helper(nums1);
        int val2 = helper(nums2);
        // cout<<val1<<endl;
        // cout<<val2<<endl;

        return max(val1, val2);

    }
};

int main()
{
    return 0;
}