// Problem:
// Given a binary tree, determine if it is height-balanced(A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.)


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

int height(Node* root, bool &ans){
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);

        if(abs(lh-rh)>1){
            ans = false;
        }

        return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
        bool ans = true;
        height(root, ans);

        return ans;
}
int main()
{
    return 0;
}