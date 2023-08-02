// PROBLEM:
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void helper(int idx, vector<int> &temp, int k, int n){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }

    for(int i=idx; i<=n; i++){
        temp.push_back(i);
        helper(i+1,temp, k, n);
        temp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    helper(1, temp, k, n);
    return ans;
}

int main()
{
    return 0;
}