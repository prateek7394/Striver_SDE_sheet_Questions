// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
// For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the 
// array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.


#include<bits/stdc++.h>
using namespace std;

// ---------------------------------- M1: My approach ----------------------
int findMin(vector<int>& nums) {
    int s=0, e=nums.size()-1;
    int ans = INT_MAX;
    if(nums[s]<=nums[e]){
        // no rotation
        ans = nums[s];
        return ans;
    }

    while(s<=e){
        int mid = s+(e-s)/2;

        // Extra checks:
        if(mid>s && nums[mid]<nums[mid-1]){
            ans = nums[mid];
            break;
        }
        if(mid<e && nums[mid+1]<nums[mid]){
            ans = nums[mid+1];
            break;
        }
        
        if(nums[s]<=nums[mid]){
            // means array from start till mid is sorted
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}

// ---------------------------- M2(Striver's approach) ------------------------------
// KEY CONCEPT: Identify the sorted half, update ans with min element in sorted half and eliminate the sorted half


#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int s=0, e=nums.size()-1;
    int ans = INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;

        if(nums[s]<=nums[e]){
            // If entire search space is sorted, then min element with be the first element
            ans = nums[s];
            break;
        }
        
        if(nums[s]<=nums[mid]){
            // means array from start till mid is sorted
            ans = min(ans, nums[s]);
            s = mid+1;
        }
        else{
            // means the other half from mid till end is sorted
            ans = min(ans, nums[mid]);
            e = mid-1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}