// PROBLEM: https://leetcode.com/problems/sliding-window-maximum/
// You are given an array of integers nums, there is a sliding window of size k which is moving from 
// the very left of the array to the very right. You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position.

// Return the max element in each sliding window.


#include<bits/stdc++.h>
using namespace std;

// -------------------------- CONCEPT: Monotonic decreasing dequeue ---------------------------------
// APPROACH: We'll maintain a dequeue of monotonically decreasing elements by storing their indices. 
// For every window of length k, we will remove all the indices of elements lying 
// outside the window and if we get an element greater than the maximum element,
// then there is no point in keeping smaller elements in the window.So, we will 
// remove all the smaller elements from the back and extract the max element 
// for each window from the front of the dequeue.

// T.C = O(n) [for loop] + O(n) [each element is pushed and popped at least once in worst case]

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        // Remove all the out of window elements from front
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        // Remove all the smaller elements from back as they are of no use
        while(!dq.empty() && nums[dq.back()]<= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        // since we can start pushing max element after the first window contains at least k elements
        // as we already got an element greater than those elements for curr window
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main()
{
    return 0;
}