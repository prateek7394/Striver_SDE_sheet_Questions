//  Problem: Find the subarray having maximum sum and print it.

#include<bits/stdc++.h>
using namespace std;


// GFG Approach: (More intuitive)
int maxSubArray1(vector<int>& nums) {
    int n= nums.size();
    int ans=nums[0];
    int maxending=nums[0]; // maxending denotes the maximum sum till ith index of the array

    for(int i=1; i<n; i++){
        maxending = max(maxending+nums[i], nums[i]);
        if(maxending>ans){
            ans = maxending;
        }
    }
    return ans;
}

// Striver's Approach:
int maxSubArray2(vector<int>& nums) {
    int maxSum=INT_MIN;
    int sum=0;

    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum>maxSum){
            // even if sum is negative but greater than maxSum, 
            // first update the maxSum then reset the sum
            maxSum=sum;
        }
        if(sum<0) sum=0; 
        // If sum at any point comes out to be -ve, then reset the sum as 
        // updating the maxSum with new +ve element itself is better than updating the maxSum
        // by adding current -ve sum with new +ve element.
    }

    return maxSum;
}

// Printing the subarray:
void printMaxSubArray(vector<int>& nums) {
    int maxSum=INT_MIN;
    int sum=0;
    int start=0, ansStart=-1, ansEnd=-1;

    for(int i=0; i<nums.size(); i++){
        if(sum==0) start=i;
        sum+=nums[i];
        if(sum>maxSum){
            ansStart=start;
            ansEnd=i;
            maxSum=sum;
        }
        if(sum<0) sum=0;
    }
    
    for(int i=ansStart; i<=ansEnd; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
    printMaxSubArray(nums);
    return 0;
}