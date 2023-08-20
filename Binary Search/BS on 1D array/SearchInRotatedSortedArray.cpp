// PROBLEM:
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
// or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.


#include<bits/stdc++.h>
using namespace std;

// ------------------------------------ M1: By finding pivot --------------------------------------
int BinarySearch(int s, int e, vector<int> arr, int target){
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m]==target){
            return m;
        }
        if(target > arr[m]){
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return -1;
}

int findPivot(vector<int> arr){
    // Pivot is that element before & after which all the elements are in ascending order
    // Here, Pivot is always the largest element
    // So, basically we have to find the largest element using binary search
    int s = 0, e = arr.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid<e && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid>s && arr[mid]<arr[mid-1]){
            return mid-1;
        }
        if(arr[mid]>arr[s]){
            // in this case all elements from 0 to mid will be smaller than mid
            // this can't be largest since in that case it would had been caught in cases 1&2
            // hence we'll ignore all the the elements upto mid
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivot = findPivot(nums);

    if(pivot==-1){
        return BinarySearch(0, nums.size()-1, nums, target);
    }

    if(nums[pivot]==target){
        return pivot;
    }

    if(target<nums[0]){
        // since target<nums[0] and all the elements after nums[0] till pivot are greater than nums[0] as elements are sorted
        // so we'll search in latter half of the array after the pivot
        return BinarySearch(pivot+1, nums.size()-1, nums, target);
    }
    else{
        return BinarySearch(0, pivot-1, nums, target);
    }
}

// ------------------------------------ M1: Using Single BS --------------------------------------
// KEY CONCEPT: Identify the sorted half and if target lies in that half, eliminate the other half
// else, eliminate the sorted half.

int search2(vector<int>& nums, int target) {
    int s = 0, e = nums.size()-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[s]<=nums[mid]){
            // left half is sorted
            if(nums[s]<=target && target < nums[mid]){
                // if target lies on the left half
                e = mid-1; // eliminate the right half 
            }
            else{
                s = mid+1; // eliminate the left half
            }
        }
        else{
            // right half is sorted
            if(nums[mid]<target && target <=nums[e]){
                // if target lies on the right half
                s = mid+1; // eliminate the left half 
            }
            else{
                e = mid-1; // eliminate the right half 
            }
        }
    }

    return -1;
}


int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;
    cout<<search2(nums, target);
    return 0;
}