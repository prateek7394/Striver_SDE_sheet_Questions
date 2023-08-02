// PROBLEM:
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

#include<bits/stdc++.h>
using namespace std;

// ************ M1: Using visited array ****************
void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis){
    vis[i][j]=1;
    int n = grid.size();
    int m = grid[0].size();

    if(i-1>=0 && grid[i-1][j]=='1' && vis[i-1][j]==0)
    {
        dfs(i-1, j, grid, vis);
    }

    if(i+1<n && grid[i+1][j]=='1' && vis[i+1][j]==0)
    {
        dfs(i+1, j, grid, vis);
    }

    if(j-1>=0 && grid[i][j-1]=='1' && vis[i][j-1]==0)
    {
        dfs(i, j-1, grid, vis);
    }

    if(j+1<m && grid[i][j+1]=='1' && vis[i][j+1]==0)
    {
        dfs(i, j+1, grid, vis);
    }
}


// ************ M2: Without using visited array(Efficient Approach) ****************

void drownEachIsland(int i, int j, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
    grid[i][j] = '0';
    drownEachIsland(i - 1, j, grid);
    drownEachIsland(i + 1, j, grid);
    drownEachIsland(i, j - 1, grid);
    drownEachIsland(i, j + 1, grid);
}


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1' && vis[i][j]==0){
                count++;
                // cout<<i<<" "<<j<<endl;
                dfs(i, j, grid, vis);
            }
        }
    }

    return count;

}


int main()
{
    vector<vector<char>> grid 
{
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
};

int ans = numIslands(grid);




    return 0;
}