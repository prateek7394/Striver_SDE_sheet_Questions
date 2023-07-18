// Given an integer array arr and an integer difference, 
// return the length of the longest subsequence in arr which is an arithmetic sequence 
// such that the difference between adjacent elements in the subsequence equals difference.

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> m;
    int ans = 1;
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(m.find(arr[i]-difference)!=m.end()){
            m[arr[i]] = 1 + m[arr[i] - difference];
        }
        else{
            m[arr[i]] = 1;
        }
        ans = max(ans, m[arr[i]]);
    }

    return ans;
}
int main()
{
    return 0;
}