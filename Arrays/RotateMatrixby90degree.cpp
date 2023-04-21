#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

//      Take transpose
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i<j){
                swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
//      Reverse each row
        for(int i=0; i<n; i++){
            for(int j=0; j<m/2; j++){
                    swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }

int main(){
    
    return 0;
}