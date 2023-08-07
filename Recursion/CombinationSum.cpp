// PROBLEM
// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. 

#include<bits/stdc++.h>
using namespace std;

// ****************** Method 1 ***********

vector<vector<int>> ans;
void solve(vector<int> &candidates, int n, int sum, int idx, vector<int> &temp, int target){
    if(sum==target){
        ans.push_back(temp);
        return;
    }

    else if(sum>target){
        return;
    }

    for(int i=idx; i<n; i++){
        temp.push_back(candidates[i]);
        sum+=candidates[i];
        solve(candidates, n, sum, i, temp, target);
        sum-=candidates[i];
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<int>temp;
    int sum=0, idx = 0;
    solve(candidates, n, sum, idx, temp, target);

    return ans;

}

// ******************** Method 2: (Striver's Approach) ****************

void helper( int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr, int target){
    if(idx == arr.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }

    if(arr[idx]<=target){
        // We can pick an element only when it is less than target
        temp.push_back(arr[idx]);
        helper(idx, temp, ans, arr, target-arr[idx]);
        temp.pop_back();
    }

    // Don't pick the element
    helper(idx+1, temp, ans, arr, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    helper(0, temp, ans, candidates, target);
    return ans;

}

int main()
{
    return 0;
}