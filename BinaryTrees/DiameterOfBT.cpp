// Problem:

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    // Constructor
    Node(int x){
        key=x;
        left=NULL;
        right=NULL;
    }
};

int height(Node* root, int &ans){
        if(root==NULL){
            return 0;
        }

        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        ans = max(ans, lh+rh);
        return 1+ max(lh, rh);  
    }

int diameterOfBinaryTree(Node* root) {
    if(root==NULL){
        return 0;
    }

    int ans = 0;
    height(root, ans); // here we don't store the return value of height as we are only concerned with diameter
    return ans;

}

int main()
{
    return 0;
}