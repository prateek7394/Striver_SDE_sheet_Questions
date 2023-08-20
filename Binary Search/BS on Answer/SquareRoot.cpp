// PROBLEM:
// You are given a non-negative integer n. Your task is to find and return its square root. 
// If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’.
// CONSTRAINTS: 0 <= n <= 10 ^ 9

#include<bits/stdc++.h>
using namespace std;

// ------------------------------ M1(My approach) ----------------------------

int floorSqrt(int n)
{
    int s = 0, e = n;
    while(s<=e){
        long long mid = (s+e)/2;
        long long sq = mid*mid; 
        if(sq==n){
            return mid;
        }
        else if(sq>n){
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
    }

    return e;
}

// ------------------------------ M1(Striver's approach) ----------------------------


int floorSqrt(int n)
{
    int s = 0, e = n;
    int ans = -1;
    while(s<=e){
        long long mid = (s+e)/2;
        long long sq = mid*mid; // to avoid overflow
        if(sq<=n){
            ans = mid; // might be an answer 
            s = mid+1; // but search for maximum possible value
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}



int main()
{
    return 0;
}