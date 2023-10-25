// PROBLEM : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Given a string s, find the length of the longest substring without repeating characters.

#include<bits/stdc++.h>
using namespace std;

// ------------------------ M1(My approach) --------------------
// T.C = O(2n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        int i=0, j=0;

        unordered_map<char, int> mp;

        for(j=0; j<n; j++){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};

// ------------------------ M2(Optimal approach) --------------------------
// T = O(n)
class Solution {
public:

    // Here if we encounter an element twice then instead of moving left pointer
    // by one step each time we directly jump i to the position just after the
    // last occurrence of current element.
    // Hence, only right pointer traverses the complete array in single traversal.
      int lengthOfLongestSubstring(string s) {
        if (s.empty()){
            return 0;
        }
        
        unordered_map<char, int> mp;
        int maxlen = 0;
        int i=0, j=0;

        for (int j=0; j<s.size(); j++) {
            if(mp.find(s[j]) != mp.end()){
                // move i to last occurrence of curr element only if it lies in the 
                // range of i to j i.e. we'll consider only that occurrence of
                // curr element that lies in our sliding window
                i = max(i, mp[s[j]]+1);
            }
            mp[s[j]] = j; // update the last occurrence to curr position
            maxlen = max(maxlen, j-i+1);
        }
        
        return maxlen;
    }
};

int main()
{
    return 0;
}


