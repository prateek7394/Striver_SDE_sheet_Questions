#include<bits/stdc++.h>
using namespace std;

// Best Solution: T=O(n*m) SC= O(1)
void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        // step 1: Traverse the matrix and
        // mark dummy row (first row) & dummy col (first col) with 0 accordingly:
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j==0){
                        col0=0;
                    }
                    else
                        matrix[0][j]=0;
                }
            }
        }

    // Step 2: Update the elements to 0 from (1,1) to (n-1, m-1) if marked:
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0|| matrix[0][j]==0)
                        matrix[i][j]=0;
                }
            }
        }
    //step 3: Finally update the elements of the 1st row(dummy row) & then 1st col(dummy col):
        if(matrix[0][0]==0){
            for(int j=0; j<n; j++){
                matrix[0][j]=0;
            }
        }

        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }
        
    }


// Optimised solution: T=O(n*m) SC= O(n+m)
void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>v(m,0);
        vector<int>h(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    v[i]=1;
                    h[j]=1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i]==1 || h[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
}


int main(){
    
    return 0;
}