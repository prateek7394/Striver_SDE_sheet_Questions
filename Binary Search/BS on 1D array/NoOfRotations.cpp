// PROBLEM:
// Given an integer array arr of size N, sorted in ascending order (with distinct values). 
// Now the array is rotated between 1 to N times which is unknown. 
// Find how many times the array has been rotated. 

#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){
    // No. of rotations is basically equal to the idx of smallest element

    int ans = 0;
    int s=0, e=arr.size()-1;

    while(s<=e){
        int mid = s+(e-s)/2;

        if(arr[s]<=arr[e]){
            // means whole array is sorted
            ans = s;
            break;
        }

        if(arr[s]<=arr[mid]){
            // left half is sorted
            if(arr[s]<arr[ans]){
                ans = s; // update the ans with the index of smallest element out of two
            }
            s = mid+1;
        }
        else{
            // right half is sorted
            if(arr[mid]<arr[ans]){
                ans = mid;
            }
            e = mid-1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}