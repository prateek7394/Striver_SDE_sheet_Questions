// PROBLEM:
// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

#include<bits/stdc++.h>
using namespace std;

// ------------------------ M1: Using upper_bound and lower_bound -------------------------
// NOTE: We can write separate function for upperBound and lowerBound instead of using pre-built functions

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    if(lb==n || nums[lb]!=target){
        // target not found
        return {-1, -1};
    }
    else{
        ans.push_back(lb);
    }

    ans.push_back(ub-1);

    return ans;
}

// ------------------------ M1: Using Simple Binary Search -------------------------

int findFirstOccurrence(vector<int>&nums, int target){
    int s=0, e=nums.size()-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid]==target){
            ans = mid;
            e = mid-1; // check for any previous occurrence
        }
        else if(nums[mid]<target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}

int findLastOccurrence(vector<int>&nums, int target){
    int s=0, e=nums.size()-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid]==target){
            ans = mid;
            s = mid+1; // check for any later occurrence
        }
        else if(nums[mid]<target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = findFirstOccurrence(nums, target);
    if(first==-1){
        // target not present in nums
        return {-1, -1};
    }
    int last = findLastOccurrence(nums, target);
    return {first, last};
}
int main()
{
    return 0;
}