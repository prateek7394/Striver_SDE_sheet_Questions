// PROBLEM: https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
// Given string str of length N. 
// The task is to find the minimum characters to be added at the front to make string palindrome.

// SOLUTION: https://www.youtube.com/watch?v=j-1NLHybCSg&t=278s 

#include<bits/stdc++.h>
using namespace std;

// ------------ NOTE --------------
// For string s = "abc":
// Perfect prefix = {"", "a", "ab"}
// Suffix = {"c", "bc", "abc", ""}

// ----------------- APPROACH -------------------------
// This problem can be solved by constructing the LPS array using KMP Algorithm
// LPS stands for longest prefix suffix array. Using LPS, we discard that part of string which is already a palindrome.
// Each index i of lps array denotes the length of the longest perfect prefix which is also
// a suffix in the substring from 0 to i.

// E.g. s = "abcbabca"
//    LPS =  00001231

vector<int>computeLPSArray(string s){
    
    int n = s.size();
    vector<int>lps(n);
    
    int len = 0;
    lps[0] = 0;
    
    int i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0; // if len pointer is already at 0th index, then make lps[i]=0 and increase i
                i++;
            }
            else{
                len = lps[len-1]; // move len pointer to lps value at prev idx
            }
        }
    }
    
    return lps;
}

int minChar(string str){
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    string s = str+"$"+rev; 
    // adding dollar is necessary for strings like aaaaaaaa
    // lps("aaaaaaaa") = 0 1 2 3 4 5 6 7  => ans = 4-7 = -3
    // lps("aaaa$aaaa")= 0 1 2 3 0 1 2 3 4 => ans = 4-4 = 0
    
    vector<int>lps = computeLPSArray(s);
    
    return n-lps.back();
}


int main()
{
    string s1 = "aaaaaaaa";
    string s2 = "aaaa$aaaa";
    vector<int>lps1 = computeLPSArray(s1);
    for(auto it: lps1){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>lps2 = computeLPSArray(s2);
    for(auto it: lps2){
        cout<<it<<" ";
    }
    return 0;
}