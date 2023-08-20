// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number 
// of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. 
// There should be atleast one 1 in the grid.

// IMPORTANT NOTE:
// While finding shortest distance, we always go with BFS

#include<bits/stdc++.h>
using namespace std;

// ------------------------------------ Using BFS -----------------------------------

// KEY POINT: 
// If dist of nearest 1 from a 0 is 1 unit, then vice-versa is also true, i.e. dis of nearest 0 from that 1 is also 1 unit
vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                // Push all 1s into the queue with dis=0 and mark them visited.
                vis[i][j]=1;
                q.push({{i, j}, 0});
            }
        }
    }
    
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    
    // For a cell(row, col), neighbours will be:
    // (row-1, col), (row, col+1), (row+1, col) & (row, col-1)
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        
        ans[row][col] = dis;
        
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow, ncol}, dis+1});
            }
        }
    }
    
    return ans;
}

int main()
{
    return 0;
}