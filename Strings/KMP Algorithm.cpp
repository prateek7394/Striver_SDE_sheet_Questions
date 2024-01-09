// PROBLEM: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// Given two strings needle and haystack, 
// return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// ---------------------- Method 1(Brute Force) ----------------------
// T.C = O(m*n)



// ---------------------- Method 2(By using KMP Algorithm) ----------------------
// T.C = O(m+n)
// References:
// https://www.youtube.com/watch?v=GTJr8OvyEVQ  -> KMP Pattern Matching Algorithm by Tushar Roy
// https://www.youtube.com/watch?v=j-1NLHybCSg&t=278s  -> Min. no. of chars to add at front to make a string palindrome

#include<bits/stdc++.h>
using namespace std;

// =================== Step 1: Generate LPS array for the pattern string ===========================
// LPS stands for Longest Prefix Suffix array. 
// Using LPS, we discard that part of string which is already a palindrome.
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
                lps[i]=0;
                i++;
            }
            else{
                len = lps[len-1]; // move len pointer to lps value at prev idx
            }
        }
    }
    
    return lps;
}

// ================= Step 2: Check for the presence of pattern in the given string ================
int strStr(string haystack, string needle) {
    int h = haystack.size(), n = needle.size();
    if(n>h) return -1;

    // Generate lps array for pattern string
    vector<int> lps = computeLPSArray(needle); 

    int i=0, j=0;

    while(i<h && j<n){
        if(haystack[i]==needle[j]){
            i++;
            j++;
        }
        else if(j>0){
            j = lps[j-1];
        }
        else{
            // if j==0
            i++;
        }
    }

    if(j==n){
        // whole needle string is found in haystack
        return i-j;
    }
    return -1;
}

int main()
{
    return 0;
}

