// PROBLEM:
// Given a string s, return the longest palindromic substring in s.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
pair<int, int> longestPalindromicSubstring(string str, int n){
    int maxlen = 0;
    pair<int, int> p = {-1,-1}; // to store the start and end pos of longest palindromic substring

    for(int s=0; s<n; s++){
        for(int e=0; e<n; e++){
            if(s==e){
                t[s][e]=1;
                if(e-s+1>maxlen){
                    maxlen = e-s+1;
                    p.first = s;
                    p.second = e;
                }
            } 
            else if(e==s+1){
                if(str[s] == str[e]){
                    t[s][e]=1;
                    if(e-s+1>maxlen){
                        maxlen = e-s+1;
                        p.first = s;
                        p.second = e;
                    }
                }
            }
        }
    }
    for(int s=n-1; s>=0; s--){
        // we start filling from bottom to up so that the value we need to fill a cell is already evaluated
        for(int e=0; e<n; e++){
            if(s<e && str[s] == str[e] && t[s+1][e-1]==1){
                t[s][e] = 1;
                if(e-s+1>maxlen){
                    maxlen = e-s+1;
                    p.first = s;
                    p.second = e;
                }
            }
        }
    }
    return p;
}

string longestPalindrome(string s) {
    int n = s.size();
    t.resize(n, vector<int>(n, 0));
    pair<int, int> p = longestPalindromicSubstring(s, n);

    string ans = "";
    for(int i=p.first; i<=p.second; i++){
        ans+=s[i];
    }
    return ans;
}

string longestPalindrome(string s) {
    int n = s.size();
    t.resize(n, vector<int>(n, -1));
    pair<int, int> p = longestPalindromicSubstring(s, n);
    cout<<p.first<<" "<<p.second<<endl;

    // string ans = "";
    // for(int i=p.first; i<=p.second; i++){
    //     ans+=s[i];
    // }
    // return ans;
    
}

int main()
{
    string ans = longestPalindrome("aaaaa");
    return 0;
}