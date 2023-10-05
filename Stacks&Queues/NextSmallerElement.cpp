// PROBLEM:
// Given an array, find the nearest smaller element G[i] for every element A[i] in the array 
// such that the element has an index smaller than i 
// G[i] for an element A[i] = an element A[j] such that 
// j is maximum possible and 
// j < i and
// A[j] < A[i]
// Elements for which no smaller element exist, consider next smaller element as -1.

#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    stack<int> st;
    
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(A[i]);
    }
    return ans;
}

int main()
{
    return 0;
}