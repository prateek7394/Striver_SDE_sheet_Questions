// You are given an m x n integer array grid. 
// There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. 
// A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int helper(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid){
    if(i>=m || j>=n){
        return 0; 
    }
    if(obstacleGrid[i][j]==1){
        return 0; // when we get an obstacle, return 0 as there is no valid path
    }
    if(i==m-1 && j==n-1){
        return 1; // we reached the final destination gives 1 valid path
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        return dp[i][j] = helper(i, j+1, m, n, obstacleGrid)+helper(i+1, j, m, n, obstacleGrid);
    }
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    dp.resize(m+1, vector<int>(n+1, -1));

    return helper(0, 0, m, n, obstacleGrid);
}

int main()
{
    return 0;
}