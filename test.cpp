#include<bits/stdc++.h>
using namespace std;

    bool check(vector<int> &nums, int m, int &sum){
        if(nums.size()>1 && sum<m){
            return false;
        }
        if(nums.size()<=2){
            return true;
        }
        
        vector<int> temp1 = nums;
        vector<int> temp2 = nums;
        int sum1 = sum - nums[nums.size()-1];
        int sum2 = sum - nums[0];
        temp1.pop_back();
        temp2.erase(temp2.begin());
        
        return check(temp1, m, sum1) || check(temp2, m, sum2);
     }
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        if(nums.size()<=2){
            return true;
        }
        return check(nums, m, sum);
    }

int main()
{
    vector<int> nums = {2, 1, 3};
    int m = 3;
    return 0;
}