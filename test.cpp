#include<bits/stdc++.h>
using namespace std;

long long maxArrayValue(vector<int>& nums) {
    long long ans = INT_MIN;
    int curr;
    
    do{
        curr = nums.size();
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<=nums[i+1]){
                int temp = nums[i]+nums[i+1];
                nums[i+1]=temp;
                nums.erase(nums.begin()+i);
            }
        }

        for(auto it: nums){
            cout<< it<<" ";
        }
        cout<<endl;
    }while(nums.size()<curr);
    
    for(auto it: nums){
        if(it>ans){
            ans = it;
        }
    }
    
    return ans;
    }

int main()
{
    vector<int> nums = {34,95,50,12,25,100,21,3,25,16,76,73,93,46,18};
    long long ans = maxArrayValue(nums);
    return 0;
}