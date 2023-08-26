// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

#include<bits/stdc++.h>
using namespace std;

// INTUTION:
// Here, we cannot apply BS on given array as the answer is not present in the array
// Also, we cannot apply BS on answer as it is applicable only in max/min questions 

// APPROACH:
// First we need to find out the two nearby indices between which kth missing no. can lie
// For this, we find the count of missing numbers at every index.
// We calculate it by comparing given array with ideal array with no missing number
// We move the start and end pointers accordingly until low<=high
// Finally high>low && ans will be arr[high]+(extra missing nos reqd)
// extra = k-missingNos
// Therefore, ans= arr[high]+(k-missingNos)
// => ans = arr[high]+(k-(arr[high]-high-1))
// => ans = k+1+high = low + k (since, low=high+1)

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int s=0, e=n-1;

    while(s<=e){
        int mid = (s+e)/2;
        int missingNumbers = arr[mid]-(mid+1);

        if(missingNumbers<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return s+k;
}



int main()
{
    return 0;
}