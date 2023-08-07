// PROBLEM:
// Given an integer n, return the number of structurally unique BST's (binary search trees)
//  which has exactly n nodes of unique values from 1 to n.

#include<bits/stdc++.h>
using namespace std;

// ************************* M1: Using DP Memoization *****************************
vector<int> dp;
int countBST(int n){
    if(n<=1){
        return 1; // single node BST and empty BST(NULL)
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int leftCount = countBST(i-1); // i-1 nodes on left
        int rightCount = countBST(n-i); // (n-1) - (i-1) on right
        ans+= leftCount * rightCount;
    }

    return dp[n]=ans;
}
int numTrees(int n) {  
    dp.resize(n+1, -1);
    return countBST(n);
}

// ************************* M1: Using Catalan Number *****************************

// The total no. of Unique BST = nth catalan number
// The first Catalan numbers for n = 0, 1, 2, 3, ... are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ....
// The nth Catalan number is given by 2nCn/(n+1) = (2n)! / (n! * (n+1)!)


int main()
{
    return 0;
}