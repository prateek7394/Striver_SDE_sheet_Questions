// Implement a last-in-first-out (LIFO) stack using only two queues.
//  The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.


#include<bits/stdc++.h>
using namespace std;

// **************************** M1: Using 2 queues **************************
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());    q1.pop();
        }
        // here we are swapping so that new element always comes at front of q2
        swap(q1, q2);
    }
    
    int pop() {
        int result = top();
        q1.pop();
        return result;
    }

    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


// **************************** M1: Using single queue **************************

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // move the last element to front 
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = top();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


int main()
{
    return 0;
}