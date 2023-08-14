// PROBLEM:
// Same as Search In A Rotated Sorted Array but here the array can contain duplicate elements

#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int s = 0, e = nums.size()-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid]==target){
            return true;
        }

        // ---------- Extra lines of code ------------
        if(nums[s]==nums[mid] && nums[mid]==nums[e]){
            // trim down the search space as these 3 cannot be equal to the target since nums[mid]!=target
            // has been already ensured in above check
            s++;
            e--;
            continue;
        }
        // -----------------------------------------------

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

    return false;
}

int main()
{
    return 0;
}