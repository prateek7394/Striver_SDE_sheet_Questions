// Question:

// You are given an m x n integer matrix matrix with the following two properties:
// 1. Each row is sorted in non-decreasing order.
// 2. The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.


#include<bits/stdc++.h>
using namespace std;

// Optimised Solution:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

//  Consider the matrix elements as a sorted array having indices from 0 to m*n-1 sorted in ascending order
//  and apply Binary search on it.

    int s=0;
    int e= m*n-1;

    while(s<=e){
        int mid = s + (e-s)/2;

//      Evaluate row and col of middle element from its index no.:
        int row = mid/n;
        int col = mid%n;
        

        if(matrix[row][col]==target){
            return true;
        }

        else if(matrix[row][col]>target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return false;
}

// T.C = log base 2(total no. of elements in matrix) = O(m*n) --> Binary Search;
// S.C = O(1);
int main()
{
    return 0;
}