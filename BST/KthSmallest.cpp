// PROBLEM:
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

// M1: Keep a track of no. of visited nodes while doing Inorder Traversal as it gives a sorted array
// We can use Morris traversal instead of Iterative and Recursive for achieving S.C = O(1)

void inorder(Node* root, int &ans, int &counter, int &k){
        if(root==NULL) {
            return;
        }
        inorder(root->left, ans, counter, k);
        counter++;
        if(counter==k){
            ans = root->val;
            return;
        }
        inorder(root->right, ans, counter, k);
}

int kthSmallest(Node* root, int k){
        int ans=-1, counter=0;
        inorder(root, ans, counter, k);
        return ans;
}

int main()
{
    return 0;
}