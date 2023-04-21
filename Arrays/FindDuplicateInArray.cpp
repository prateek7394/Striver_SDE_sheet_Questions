
// Question:
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.



#include<bits/stdc++.h>
using namespace std;

// ****** Using Linked List Cycle Detection Method:

int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow = nums[0];
        int fast = nums[0];


        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //Move one of the pointers to the starting point and then move both pointers by 1
        slow = nums[0]; 
        // The second meeting point of ptrs will be the duplicate element
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
int main(){
    
    return 0;
}