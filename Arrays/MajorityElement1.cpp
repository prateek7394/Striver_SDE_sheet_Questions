// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
//  You may assume that the majority element always exists in the array.

#include<bits/stdc++.h>
using namespace std;

// Optimal Approach (***** Moore's Voting Algorithm ******  ):
// Intution: 
// We divide the array into subarrays based on count and check if an element is majority element in that subarray.
// i.e. if occurrence of that element is greater than the total occurrence of other elements in that subarray
// then it is a majority element and if there exists a majority element then it would be the
// final value stored in ele variable otherwise not. So run a loop to verify it.

// T.C = O(n)
// S.C = O(1)

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    
    int ele;
    int count = 0;

    for(int i=0; i<n; i++){
        if(count==0){
            ele = nums[i];
            count = 1;
        }
        else if(nums[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }

    count=0;

//  Verify if ele is actually majority element or not
    for(int i=0; i<n; i++){
        if(nums[i]==ele){
            count++;
        }
    }

    if(count>n/2){
        return ele;
    }

    return -1;
}

int main()
{
    return 0;
}