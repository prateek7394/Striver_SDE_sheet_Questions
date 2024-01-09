// PROBLEM: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

#include<bits/stdc++.h>
using namespace std;
    // to check if requiredSum is possible to get by splitting array in k or less then k subarray
    bool isValid(int arr[],int requiredSum,int k,int n) {
        int sum=0,count=1;
        for(int i=0;i<n;i++) {
            if(sum+arr[i]<=requiredSum) {
                sum+=arr[i];
            }            
            else {
                sum=arr[i];
                count++; // new subarray starts
            }
        }
        // If we can maintain maxSum as requiredSum in <= k subarrays, then it may be a potential ans
        // NOTE: 
        // Even if we can achieve maxSum as requiredSum in < k subarrays,
        // then also we can split any subarray into 2 to make total
        // k splits as sum of each parition of any subarray will be 
        // less than requiredSum
        return count<=k;
}

int splitArray(int arr[] ,int N, int K) {
        // code here
        int totalSum =0,mx=INT_MIN;
        for(int i=0;i<N;i++) {
            totalSum+=arr[i];
            mx = max(mx,arr[i]);
        }
        
        // when K=1, ans = totalSum
        // when K=N, ans = maxSum

        int lo=mx,hi=totalSum,ans=INT_MAX;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(isValid(arr,mid,K,N)) {
                ans=mid;
                hi=mid-1;   // To minimize our answer
            } else {
                lo=mid+1;   // To get Valid Range
            }
        }
        return ans;
    }
int main()
{
    return 0;
}