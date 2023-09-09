// PROBLEM: https://leetcode.com/problems/rotting-oranges/description/
// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
// If this is impossible, return -1.

// SIMILAR QUESTION: 01 Matrix

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    int fresh=0;

    vector<vector<int>>vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

// Push all the rotten oranges into the queue
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==2){
                q.push({i, j});
            }
            if(grid[i][j]==1){
                fresh++;
            }
        }
    }

    int delrow[]= {-1, 0, 1, 0};
    int delcol[]= {0, 1, 0, -1};

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow, ncol});
                    fresh--;
                }
            }
        }
        ans++;
    }

    if(fresh>0){
        return -1;
    }

    // the last iteration that converts all the final fresh 
    // oranges to rotten will push those indices in the queue 
    // and we will get our ans+1, so return ans -1

    // Also, if there are no rotten oranges, then ans will
    // not be incremented, so return 0

    return ans>0 ? ans-1: ans;

}

int main()
{
    return 0;
}