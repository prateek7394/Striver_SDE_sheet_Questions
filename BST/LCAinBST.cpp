// PROBLEM:
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root==p || root==q){
            return root;
        }
        
        // If both lie on left side of the root
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        } 

        // If both lie on right side of the root
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        // If one lies on left and other lies on right side of the root
        else{
            return root;
        }
    }


int main()
{
    return 0;
}