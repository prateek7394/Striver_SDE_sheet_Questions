// Problem statement:

// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
//  The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths 
// that the robot can take to reach the bottom-right corner.

// SOLUTION:

// Using DP(Memoization):
int t[101][101];

int uniquePaths(int m, int n) {
    if(m==1 || n==1){
            return 1;
    }

    if(t[m][n]!=-1){
        return t[m][n];
    }
    else{
        t[m][n] = uniquePaths(m, n-1) + uniquePaths(m-1, n);
        return t[m][n];
    } 
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    memset(t, -1, sizeof(t));
    return 0;
}