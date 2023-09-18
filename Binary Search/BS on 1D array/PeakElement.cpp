// PROBLEM:
// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. 
// If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be 
// strictly greater than a neighbor that is outside the arr.


// APPROACH:
// Suppose we have only one peak in the arr. So, the graph will be somewhat increasing and then decreasing.
// We calculated mid and it is greater than mid-1, that means we are on increasing slope and peak is on right.
// Else,we are on decreasing slope and peak is on the left.
// Now, if we have multiple peaks, then even if we discard left or right portion of the mid, we'll definitely
// get a peak on the other portion of the mid.

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n==1){
        return 0;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    else if(nums[n-1]>nums[n-2]){
        return n-1;
    }

    int s=1, e=n-2;

    while(s<=e){
        int mid = (s+e)/2;

        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            return mid;
        }

        else if(nums[mid]>nums[mid-1]){
            // mid lies on the increasing slope which means
            // Peak lies on the right side of mid
            s = mid+1; 
        }
        else{
            // implies mid lies on decreasing slope
            // hence, peak lies on the left side of mid
            e = mid-1;
        }
    }
    return -1;
}

int main()
{
    return 0;
}