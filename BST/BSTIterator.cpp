// PROBLEM:
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(Node root): Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

// boolean hasNext(): Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.

// int next(): Moves the pointer to the right, then returns the number at the pointer.

// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Optimal Solution using Stack:
// T=O(1) on average, as we are pushing n nodes in stack and we may have n calls, so avg time taken per next call = O(n/n) = O(1)
// S.C = O(h) as we are storing left elements only

class BSTIterator {
public:
    stack<Node*> s;
    void GoToExtremeLeft(Node* root){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(Node* root) {
        GoToExtremeLeft(root);
    }

    int next() {
        Node* top = s.top();
        s.pop();
        Node* right = top->right;
        GoToExtremeLeft(right);
        return top->val;
    }
    
    bool hasNext() {
        return s.empty() ? false: true;
    }
};


int main()
{
    return 0;
}