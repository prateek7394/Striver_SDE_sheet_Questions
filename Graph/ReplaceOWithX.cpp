// PROBLEM:
// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' 
// that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, 
// just above, just left and just right of it.

#include<bits/stdc++.h>
using namespace std;

// APPROACH:
// The set of O's that are connected to the any of the boundaries of matrix cannot be transformed into X

// --------------------------- M2(Using visited array) -------------------------------


void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis){
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col]=1;
    
    int delrow[]= {-1, 0, 1, 0};
    int delcol[]= {0, 1, 0, -1};
    
    for(int i=0; i<4; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow, ncol, mat, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='O'){
                dfs(i, j, mat, vis);
            }
        }
    }
    
    // convert all the unvisited elements(which includes non-boundary O's) into X
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]){
                mat[i][j]='X';
            }
        }
    }
    
    return mat;
}


// --------------------------- M2(Without using visited array) -------------------------------

void dfs(int row, int col, vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();

    board[row][col]='P';

    int del[5]={-1,0, 1, 0, -1};

    for(int i=0; i<4; i++){
        int nrow = row + del[i];
        int ncol = col + del[i+1];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && board[nrow][ncol]!='P'){
            dfs(nrow, ncol, board);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                dfs(i, j, board);
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='P'){
                board[i][j]='O';
            }
            else{
                board[i][j]='X';
            }
        }
    }
}
int main()
{
    return 0;
}