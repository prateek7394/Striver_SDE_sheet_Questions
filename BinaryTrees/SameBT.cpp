// Problem:
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            // If both the nodes are NULL , return true
            return true;
        }
        if(p==NULL || q==NULL){
            // If only one of the nodes is NULL, return false
            return false;
        }

        //  If both the nodes are not NULL, then:
        return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

int main()
{
    return 0;
}