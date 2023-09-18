// PROBLEM:
// Implement a first in first out (FIFO) queue using only two stacks. 
// The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.

#include<bits/stdc++.h>
using namespace std;

// ********************* Method 1 *****************
// T.C = O(n) [for push operation] + O(1)[rest]
// S.C = O(2n) 

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}
    
    void push(int x) {
        // move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // push new element in s1
        s1.push(x);
        // move the elements back to s1 from s2
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = peek();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// ************************* Method 2 ****************************
// T.C = amortised O(1) because at only some instances, peek() and pop() performs O(n) operation and
// for remaining instances it is O(1) while push is always O(1)
// S.C = O(2n)


class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ans = peek();
        output.pop();
        return ans;
    }
    
    int peek() {
        if(output.empty()){
            while (!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty(void) {
        return input.empty() && output.empty();
    }
};


// ************************* Method 3: Using Single stack ****************************
class MyQueue {
public:
    stack<int> st;
    MyQueue() {}
    
    void push(int x) {
        if(st.empty()){
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();
        push(x);
        st.push(top);
        return;
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

int main()
{
    return 0;
}