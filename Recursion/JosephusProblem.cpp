// PROBLEM: https://www.geeksforgeeks.org/problems/josephus-problem/1

#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int n, int k, vector<int>&v){
    if(v.size()==1){
        return v[0];
    }
    idx = (idx+k-1)%v.size(); 
    v.erase(v.begin()+idx); // since we have to kill (k-1)th person from current person
    return helper(idx, n, k, v);
}
int josephus(int n, int k)
{
    vector<int>v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    
    return helper(0, n, k, v);
}
int main()
{
    return 0;
}