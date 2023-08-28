// PROBLEM:
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include<bits/stdc++.h>
using namespace std;

// APPROACH:
// sort the strings in lexicographical order and compare only the first and last strings
// since first and last strings will have the max difference

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    sort(strs.begin(), strs.end()); 
    string ans = "";

    string first = strs[0];
    string last = strs[n-1];
    int idx=0;

    while(idx<first.size() && idx<last.size()){
        if(first[idx]!=last[idx]){
            return ans;
        }
        else{
            ans+=first[idx];
        }
        idx++;
    }

    return ans;
}

int main()
{
    return 0;
}