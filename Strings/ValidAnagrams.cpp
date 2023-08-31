// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

#include<bits/stdc++.h>
using namespace std;

// ------------------------ Method 1 ----------------------------

bool isAnagram(string s, string t) {
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    return s==t;
}

// ------------------------ Method 2 ----------------------------

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }
    vector<int>freq(26,0);

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    // Frequency of all the chars must be zero to be anagram
    for(int i=0; i<26; i++){
        if(freq[i]!=0) return false;
    }

    return true;
}


int main()
{
    return 0;
}