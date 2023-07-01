#include<bits/stdc++.h>
using namespace std;

// T.C = O(log n);
double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long long num = n; 
        // to avoid overflow when n = -2^31 then -n = 2^31
        // but range of int is from -2^31 to 2^31-1 only so convert int to long long
        
        if(num<0){
            num = -num;
            x = 1/x;
        }
        return (num%2==0)? myPow(x*x, num/2): x*myPow(x*x, num/2);
}

int main()
{
    return 0;
}