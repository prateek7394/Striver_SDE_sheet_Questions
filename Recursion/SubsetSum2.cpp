// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;


// *************** M1: Using set(By Aditya Verma) *************
// T = O(2^n)[for recursion] + O(mlogm) [for inserting each subset into set] + O(nlogn) [for sorting nums array]
// where m = 2^n(total no. of subsets)

void solve(vector<int> nums, set<vector<int>> &s, vector<int> temp){
    int n = nums.size();
    if(n==0){
        s.insert(temp);
        return;
    }

    vector<int> op1 = temp;
    vector<int> op2 = temp;
    op2.push_back(nums[n-1]);
    nums.pop_back();

    solve(nums, s, op1);
    solve(nums, s, op2);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // n log n
    set<vector<int>> s;
    vector<int> temp;
    solve(nums, s, temp);

    vector<vector<int>> ans(s.begin(), s.end());

    return ans; 

}

// ************* Method 2(Optimised Approach): By Striver
// T.C = O(2^n [for recursion] * n[for copying subsets into ans vector]) + O(nlogn) for sorting nums array
// S.C = O(2^n) * K(avg. length of each subset)
// A.S = O(n) for recursive call stack

void findSubsets(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
    ans.push_back(temp);

    for(int i=idx; i<nums.size(); i++){
        if(i>idx && nums[i]==nums[i-1]){
            continue;
        }
        else{
            // we can pick an element for the first time it is called in a recursive call
            temp.push_back(nums[i]);
            findSubsets(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // so that all similar elements can stay together
    vector<int> temp;
    vector<vector<int>> ans;
    findSubsets(0, nums, temp, ans);
    return ans; 

}

int main()
{
    vector<int> nums = {1,2,2};
    vector<vector<int>> v = subsetsWithDup2(nums);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout <<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}