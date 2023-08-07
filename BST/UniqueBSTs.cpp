// PROBLEM:
// Given an integer n, return all the structurally unique BST's (binary search trees), 
// which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

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


vector<Node*> generateBST(int s, int e){
    vector<Node*> ans;
    if(s>e){
        // No nodes available in that range
        ans.push_back(NULL);
        return ans;
    }

    for(int i=s; i<=e; i++){
        vector<Node*> left = generateBST(s, i-1);
        vector<Node*> right = generateBST(i+1, e);

        for(auto l: left){
            for(auto r: right){
                Node *root = new Node(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }

    return ans;
}

vector<Node*> generateTrees(int n) {
    return generateBST(1, n);
}

int main()
{
    return 0;
}