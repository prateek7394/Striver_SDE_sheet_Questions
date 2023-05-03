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

// Iterative Approach:

void inorderIterative(Node* root, vector<int> &ans){
    Node *temp = root;
    stack<Node*> st;

    while(!st.empty() || temp!=NULL){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();

        ans.push_back(temp->key);
        temp = temp->right;
    }
}

// Recursive Approach:

void inorderRecursive(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorderRecursive(root->left, ans);
        ans.push_back(root->key);
        inorderRecursive(root->right, ans);
    }

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(5);
    root->left->left = new Node(30);
    root->left->right = new Node(7);
    root->right->right = new Node(6);

    vector<int>ans;
    // inorderRecursive(root, ans);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    inorderIterative(root, ans);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}