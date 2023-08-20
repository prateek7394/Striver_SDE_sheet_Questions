// PROBLEM:
// You are given a sorted array consisting of only integers where every element appears exactly twice, 
// except for one element which appears exactly once.
// Return the single element that appears only once.


#include<bits/stdc++.h>
using namespace std;

// ------------------------- M1: My approach ----------------------------------
// KEY CONCEPT: Elements lying to the left of single element have first occurrence at even idx && 2nd occurrence at odd index
// while the Elements lying to the right of single element have first occurrence at odd idx && 2nd occurrence at even index

int singleNonDuplicate(vector<int>& nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    int s=0, e=n-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        // edge case 1
        if(mid==0){
            if(nums[mid+1]==nums[mid]){
                s = mid+2;
            }
            else{
                ans = nums[mid];
                break;
            }
        }

        // edge case 2
        else if(mid==n-1){
            if(nums[mid]==nums[mid-1]){
                e = mid-2;
            }
            else{
                ans = nums[mid];
                break;
            }
        }

        else if(nums[mid]==nums[mid+1]){
            if(mid%2!=0){
                // single element lies in the left half
                e = mid-1;
            }
            else{
                // single element lies in the right half
                s = mid+2;
            }
        }
        else if(nums[mid]==nums[mid-1]){
            if((mid-1)%2!=0){
            // single element lies in the left half
                e = mid-2;
            }
            else{
            // single element lies in the right half
                s = mid+1;
            }
        }

        else{
            // element is neither equal to its next or previous element
            ans = nums[mid];
            break;
        }
    }

    return ans;
}

// -------------------------------------- M2(Striver's approach) -------------------------

int singleNonDuplicate(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!= nums[n-2]) return nums[n-1];

    int s=1, e=n-2;
    while(s<=e){
        int mid = (s+e)/2;

        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];
        }

        if((mid%2==0 && nums[mid+1]==nums[mid]) or (mid%2==1 && nums[mid-1]==nums[mid])){
            // we are in the left half and element is in the right half
            s = mid+1;
        }
        else{
            // we are in the right half and element is in the left half
            e = mid-1;
        }
    }

    return -1;
} 

int main()
{
    return 0;
}