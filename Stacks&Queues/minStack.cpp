// PROBLEM

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include<bits/stdc++.h>
using namespace std;

// ***************** M1: Using single stack **************** 
// S.C = O(2n)
class MinStack {
public:
    stack<pair<int, int>> st;
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else{
            st.push({val, min(st.top().second, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;;
    }
};


int main()
{
    return 0;
}