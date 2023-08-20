// Given two numbers N and M, find the Nth root of M. 
// The nth root of a number M is defined as a number X when raised to the power N equals M. 
// If the ‘nth root is not an integer, return -1.

#include<bits/stdc++.h>
using namespace std;

// We created this function as pow(mid, n) can overflow for large value of n
long long check(int mid, int n, int m){
    long long val = 1;
    for(int i=1; i<=n; i++){
        val = val*mid;
        if(val>m) return 2;
    }

    if(val==m) return 1;
    else return 0;
}

int NthRoot(int n, int m) {
    int s=1, e=m;
    int ans = -1;

    while(s<=e){
        long long mid = (s+e)/2;
        long long val = check(mid, n, m);
        if(val==1){
            // nth root of mid is equal to m
            ans = mid;
            break;
        }
        else if(val==2){
            // nth root of mid is greater than m
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}