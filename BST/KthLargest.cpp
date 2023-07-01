// PROBLEM:
// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

// ********** M1: Kth largest = (n-K+1)th smallest 
// Do one traversal to find total no. of nodes(n) and another traversal to find ans.

void countNodes(Node* root, int &totalNodes){
        if(root==NULL) {
            return;
        }
        countNodes(root->left, totalNodes);
        totalNodes++;
        countNodes(root->right, totalNodes);
    }
    
void inorder(Node* root, int &ans, int &counter, int &k, int &totalNodes){
    if(root==NULL) {
        return;
    }
    inorder(root->left, ans, counter, k, totalNodes);
    counter++;
    if(counter==totalNodes-k+1){
        ans = root->val;
        return;
    }
    inorder(root->right, ans, counter, k, totalNodes);
}


// *********** M2: Do Reverse inorder traversal(Right, root, Left);

void inorder(Node* root, int &ans, int &counter, int &k){
    if(root==NULL) {
        return;
    }
    inorder(root->right, ans, counter, k);
    counter++;
    if(counter==k){
        ans = root->val;
        return;
    }
    inorder(root->left, ans, counter, k);
}

int kthLargest(Node *root, int K)
{
    int ans=-1, counter=0, totalNodes=0;
    countNodes(root, totalNodes);
    inorder(root, ans, counter, K, totalNodes);
    return ans;
}


int main()
{
    return 0;
}