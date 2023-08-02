// PROBLEM:
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, 
// which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.



#include<bits/stdc++.h>
using namespace std;

// APPROACH:
// For circular array, we assume an imaginary array of twice the length of original array
// having copied elements and apply nge method for single array

// T.C = O(2n) + O(2n)

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    stack<int>st;
    vector<int> ng(n);

    for(int i=2*n-1; i>=0; i--){
    // run a loop for twice the length of the given array
        while(!st.empty() && st.top()<=nums[i%n]){
            // we pop all equal or smaller elements at stack top
            st.pop();
        }

        if(i<n){
            // since we need nge for elements till n-1,
            //  we ignore elements beyond n
            if(st.empty()){
                ng[i] = -1;
            }
            else{
                ng[i] = st.top();
            }
        }
        st.push(nums[i%n]);
    }

    return ng;
}

int main()
{
    vector<int> nums = {5,-1, 0, 8, 2};
    vector<int> ans = nextGreaterElement(nums);
    return 0;
}