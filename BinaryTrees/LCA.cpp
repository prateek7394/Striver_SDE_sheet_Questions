// Problem:
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// *********** M1: Find the path from root to each node and return the last common node in both *******

bool path(TreeNode *root, vector<TreeNode *> &ans, TreeNode *x)
{
    if (root == NULL)
    {
        return false;
    }

    ans.push_back(root);
    if (root == x)
    {
        return true;
    }

    bool leftCall = path(root->left, ans, x);
    bool rightCall = path(root->right, ans, x);

    if ((leftCall || rightCall) == false)
    {
        ans.pop_back();
        return false;
    }
    return true;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> path1;
    vector<TreeNode *> path2;
    path(root, path1, p);
    path(root, path2, q);

    int n = min(path1.size(), path2.size());
    int i;
    for (i = 0; i < n; i++)
    {
        if (path1[i] != path2[i])
            break;
    }

    return path1[i - 1];
}


// ***************** M2: Using Recursion ************** 
// T.C= O(n), S.C = O(n)


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            // If current root is equal to any of the nodes or is NULL
            return root;
        }

        TreeNode* leftCall = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightCall = lowestCommonAncestor(root->right, p, q);

        if(leftCall==NULL && rightCall==NULL){
            return NULL;
        }

        else if(leftCall==NULL){
            return rightCall;
        }

        else if(rightCall==NULL){
            return leftCall;
        }
        else{
            // If both the nodes are found, that means given root is the ancestor of the two nodes
            // since we can reach both the nodes from current root
            return root;
        }
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    lowestCommonAncestor(root, root->left, root->left->right->right);
    return 0;
}