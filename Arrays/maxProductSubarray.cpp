// Given an integer array nums, find a subarray that has the largest product, and return the product.

#include<bits/stdc++.h>
using namespace std;


// ********************* Method 1 *******************

int maxProduct(vector<int>& nums) {
    int currMax = nums[0], currMin = nums[0], ans = nums[0];
    int n = nums.size();

    for(int i=1; i<n; i++){
        if(nums[i]<0){
            // on multiplying with negative number, max will become min and min will become max
            swap(currMax, currMin);
        }

        currMax = max(nums[i], currMax*nums[i]);
        currMin = min(nums[i], currMin*nums[i]);

        ans = max(ans, currMax);
    }

    return ans;

}

// **************** Method 2(Two Pointer Approach) *********************

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int l=1,r=1;
    int ans = nums[0];
    
    for(int i=0;i<n;i++){
        
        //if any of l or r become 0 then update it to 1
        if(l==0) l=1;
        if(r==0) r=1;
        
        l *= nums[i];   //prefix product
        r *= nums[n-1-i];   //suffix product
        
        ans = max(ans,max(l,r));
        
    }
    
    return ans;

}

int main()
{
    return 0;
}