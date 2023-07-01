// PROBLEM:
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

// *********** M1: Find inorder traversal and check if it is strictly increasing or not

// ********** M2: Assign a range to each node in which its value can lie ********
// T=O(n), SC = O(n)

// APPROACH:
// For root, let the range be (INT_MIN, INT_MAX)
// Upon moving left, update maxValue to root->val and upon moving right, update minValue to root->val

bool checkInRange(Node*root, long minValue, long maxValue){
    if(root==NULL){
        return true;
    }
    if(root->val<= minValue || root->val>= maxValue){
        return false;
    }

    return checkInRange(root->left, minValue, root->val) && checkInRange(root->right, root->val, maxValue); 
}
bool isValidBST(Node* root) {
    return checkInRange(root, LONG_MIN, LONG_MAX);
}


int main()
{
    return 0;
}   