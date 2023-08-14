// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take
// to reach the bottom-right corner.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int countPaths(int i, int j, int m, int n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    else if(i==m || j==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int moveRight = countPaths(i, j+1, m, n);
    int moveDown = countPaths(i+1, j, m, n);
    return dp[i][j] = moveRight+moveDown;
}
int uniquePaths(int m, int n) {
    dp.resize(m+1, vector<int>(n+1, -1));
    return countPaths(0, 0, m, n);
}

int main()
{
    return 0;
}