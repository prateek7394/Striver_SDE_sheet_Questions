// PROBLEM:
// Given an integer n, return a list of all possible full binary trees with n nodes.
// Each node of each tree in the answer must have Node.val == 0.
// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// ********************************** IMPORTANT POINTS *******************
// 1-> A full binary tree always contains odd no. of roots
// 2-> We always have odd no. of nodes on the LHS as well as RHS of the root node in a FBT
// 2-> So, total no. of nodes in a FBT = odd+odd+1 = odd


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

vector<Node*> allPossibleFBT(int n) {
    if(n==1){
        vector<Node*> v;
        v.push_back(new Node(0));
        return v;
    }
    vector<Node*> ans;
    for(int i=1; i<n; i+=2){
        // we can only keep odd no. of nodes on left and right for having a
        // full binary tree since it always contain odd no. of roots
        vector<Node*> left = allPossibleFBT(i); // no. of nodes in LHS = i
        vector<Node*> right = allPossibleFBT(n-1-i); // no. of nodes in LHS = n-1-i

        // for each left and right FBT, attach it with curr node(root node)
        // to get all possible combinations
        for(auto l: left){
            for(auto r: right){
                Node* root = new Node(0);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }

    }
    return ans;
}
int main()
{
    return 0;
}