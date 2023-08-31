// PROBLEM LINK: https://leetcode.com/problems/string-to-integer-atoi/description/

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int n=s.size();
    if(n==0){
        return 0;
    }
    bool isNegative = false;
    int i=0;
    while(i<n && s[i]==' '){
        i++;
    }
    if(i==n){
        return 0;
    }

    if(s[i]=='-'){
        isNegative=true;
        i++;
    }
    else if(s[i]=='+'){
        i++;
    }
    if(s[i]=='.'){
        return 0;
    }

    int ans = 0;
    while(i<n && s[i]>='0' && s[i]<='9'){
        int digit = s[i] - '0';

        // To avoid integer overflow:
        // ans = 214748365(suppose) -> 9 digits
        // Integer_MAX = 2147483647 -> 10 digits
        // Integer_MAX/10 = 214748364 -> 9 digits

        // If ans > INT_MAX / 10, then appending even 0 will lead to Overflow
        // else if ans==INT_MAX, then we can append only digits from 0 to 7
        // else if ans<INT_MAX, we can append any digit from 0 to 9 as overall
        // no. will be less than INT_MAX
        if(ans > (INT_MAX / 10) || (ans == (INT_MAX / 10) && digit > 7)){
            return isNegative ? INT_MIN : INT_MAX;
        }

        ans = (ans * 10) + digit; // adding digits at their desired place-value
        i++;
    }

    return isNegative? ans*(-1) : ans;
}


int main()
{
    return 0;
}