#include<bits/stdc++.h>
using namespace std;

// M1: Using unordered_map
int helper(string &s){
    int count = 1;
    unordered_map<char, int> m;
    
    for(int i=0; i<s.size(); i++){
        if(m.find(s[i])==m.end()){
            m[s[i]] = count;
            count*=2;
        }
        else{
            int temp = m[s[i]];
            m[s[i]] = count;
            count*=2;
            count-= temp;
        }
    }
    return count;
    
}

// M2: Using DP(try later)

 int countSub(string str) {
    vector<int> last(127, -1);
    int n = str.length();
    int dp[n + 1];
    
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1];
    
        if (last[str[i - 1]] != -1)
            dp[i] = dp[i] - dp[last[str[i - 1]]];
    
        last[str[i - 1]] = (i - 1);
    }
    return dp[n];
}

int main()
{
    return 0;
}