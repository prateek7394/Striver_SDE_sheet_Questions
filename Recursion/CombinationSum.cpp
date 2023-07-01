#include<bits/stdc++.h>
using namespace std;

// ****************** Method 1 ***********

vector<vector<int>> ans;
void solve(vector<int> &candidates, int n, int sum, int currIdx, vector<int> &temp, int target){
    if(sum==target){
        ans.push_back(temp);
        return;
    }

    else if(sum>target){
        return;
    }

    for(int i=currIdx; i<n; i++){
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
    int sum=0, currIdx = 0;
    solve(candidates, n, sum, currIdx, temp, target);

    return ans;

}

// ******************** Method 2: (Striver's Approach) ****************

void helper( int currIdx, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr, int target){
    if(currIdx == arr.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }

    // Pickup an element

    if(arr[currIdx]<=target){
        temp.push_back(arr[currIdx]);
        helper(currIdx, temp, ans, arr, target-arr[currIdx]);
        temp.pop_back();
    }

    // Don't pick the element and move to next element
    helper(currIdx+1, temp, ans, arr, target);
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