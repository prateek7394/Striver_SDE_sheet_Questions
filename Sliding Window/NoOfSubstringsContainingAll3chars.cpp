// PROBLEM: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    unordered_map<char, int> mp;
    int i=0, j, e=s.size()-1;
    int count=0;

    for(j=0; j<s.size(); j++){
        mp[s[j]]++;

        while(mp['a'] && mp['b'] && mp['c']){
            // When we get a valid substring, then the total no of substrings formed 
            // from that char till end will be 1(curr substring) + no of remaining characters (e-j+1)
            count+=(e-j+1);
            mp[s[i]]--;
            i++;
        }
    }
    return count;
}

int main()
{
    return 0;
}


