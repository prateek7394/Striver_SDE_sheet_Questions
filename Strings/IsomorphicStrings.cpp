// PROBLEM:
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.

// LINK: https://leetcode.com/problems/isomorphic-strings/description/

#include<bits/stdc++.h>
using namespace std;

//  IMP: The strings characters may be any valid ASCII character and there must be
//  one-one bidirectional mapping of characters


// ============================ Method 1: My Approach ====================================

bool isIsomorphic(string s, string t) {
    unordered_map<char,char> mp;
    vector<int>vis(256, 0); // since there are 256 ascii characters

    for(int i=0; i<s.size(); i++){
        if(mp.count(s[i])==1 && mp[s[i]]!=t[i]){
            // if there are diff. chars in t for same char in s
            return false;
        }
        else if(mp.count(s[i])==0 && vis[int(t[i])]==1){
            // If an element in t is already mapped with an element in s
            // In this case, we cannot map two characters of s with same
            // character of t
            return false;
        }
        else{
            mp[s[i]] =  t[i];
            vis[int(t[i])] = 1;
        }
    }
    return true;
}

// ============================ Method 2 ====================================

bool isIsomorphic(string s, string t) {
    int n = s.size();
    int m1[256] = {0};
    int m2[256] = {0};

    for(int i=0; i<n; i++){
        if(!m1[s[i]] && !m2[t[i]]){
            // map ascii value char of s with ascii value of char of t and vice-versa
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else if(m1[s[i]] != t[i]){
            // if char at s is already mapped with some char of t but that value is not
            //  matching with curr char of t
            return false;
        }
    }

    return true;
}

int main()
{
    return 0;
}