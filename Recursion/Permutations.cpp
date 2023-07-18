// Given an array nums of distinct integers, return all the possible permutations. You can return the answer
//  in any order.

#include <bits/stdc++.h>
using namespace std;

// ************** Method 1: Using extra space(vector<int> vis) **********
// T.C = O(n![no. of possible permutations] * n[for loop])
// S.C = O(n)[for temp] + O(n)[for vis] 
// A.S = O(n) --> for recursion calls + O(n!)--> for ans vector

void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &vis)
{
    if (temp.size() == nums.size())
    {
        ans.push_back(temp);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        // run a loop from 0 to n-1 for every recursive call
        if (vis[i] == 1) continue;
        temp.push_back(nums[i]);
        vis[i] = 1;
        helper(nums, ans, temp, vis);
        vis[i] = 0;
        temp.pop_back();
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> vis(nums.size(), 0);
    helper(nums, ans, temp, vis);
    return ans;
}

// *********** Method 2 ****************
// By swapping elements and bringing each element to every possible index
// T.C = O(n!*n)
// S.C = O(1)
// A.S = O(n) --> for recursion calls + O(n!)--> for ans vector

void helper(int idx, vector<int> nums, vector<vector<int>> &ans){
    if(idx==nums.size()){
        ans.push_back(nums);
    }

    for(int i=idx; i<nums.size(); i++){
        // here we are assuming a pointer which starts from 0 and goes till n-1
        // for each position(index) of pointer, we can swap an element at a particular index with itself && elements at its position

        swap(nums[idx], nums[i]);
        helper(idx+1, nums, ans);
        swap(nums[i], nums[idx]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;

    helper(0, nums, ans);
    return ans;
}
int main()
{
    return 0;
}