// PROBLEM: https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
using namespace std;

// APPROACH : 

// similar to LIS problem
// only difference is that in LIS we check for increasing order
// But here, we have to check whether latter
// string is a subsequence of former string and differing by 1 char only



     bool isSubsequence(string &s, string &t) {
        // s->smaller string
        // t->larger string
        if(t.size()-s.size()!=1){
            return false;
        }
        int i=0, j=0;

        while(i<s.size() && j<t.size()){
            if(s[i]!=t[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }

        if(i==s.size()){
            return true;
        }
        return false;
    }

    static bool cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(isSubsequence(words[j], words[i])){
                    dp[i] =  max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        for(auto it: dp){
            cout<<it<<" ";
        }

        return ans;
    }


int main()
{
    vector<string> words = {"a","b","ba","bca","bda","bdca"};

    longestStrChain(words);
    
    return 0;
}