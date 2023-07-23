// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

#include<bits/stdc++.h>
using namespace std;

// ********************************** My Approach: By storing nge in an array and using unordered_map ***************
// T.C = O(n^2)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ng;
    int i, j;
    for(i=0; i<n2; i++){
        for(j=i+1; j<n2; j++){
            if(nums2[j]>nums2[i]){
                ng.push_back(nums2[j]);
                break;
            }
        }
        if(j==n2){
            ng.push_back(-1);
        }
    }

    unordered_map<int, int> m;
    for(int i=0; i<n2; i++){
        m[nums2[i]] = i;
    }

    vector<int> ans;
    for(auto it: nums1){
        int idx = m[it];
        ans.push_back(ng[idx]);
    }

    return ans;
}


// ************************* Optimal Approach : Using stack to find nge and unordered_map to store it ***************
// T.C = O(n)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;

    for(auto it: nums2){
        while(!s.empty() && it > s.top()){
            // if we encounter an element > st.top(), we store it as its nge and pop it 
            // and keep checking till this condition remains true
            m[s.top()] = it;
            s.pop();
        }
        s.push(it);
    }

    vector<int> ans;
    for(auto it: nums1){
        if(m.count(it)){
            ans.push_back(m[it]);
        }
        else{
            ans.push_back(-1);
        }
    }

    return ans;
}

// **************************** M3(Striver's Approach- More Intuitive) ****************
// -> Start from the last element and keep removing the elements smaller than current element on the stack top
// -> Once we get an element > curr Element we store it as its nge


int main()
{
    return 0;
}