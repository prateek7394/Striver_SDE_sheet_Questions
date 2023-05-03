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

void preorderIterative(Node* root, vector<int> &ans){
    // ************* Method 1: By modifying Inorder Iterative code *************

    // Node *temp = root;
    // stack<Node*> st;

    // while(!st.empty() || temp!=NULL){
    //     while(temp!=NULL){
    //         st.push(temp);
    //         ans.push_back(temp->key);
    //         temp = temp->left;
    //     }
    //     temp = st.top();
    //     st.pop();

    //     temp = temp->right;
    // }

    // ************** Method 2 **************

    if(root == NULL){
        return;
    }

    stack<Node*> st;
    Node*temp = root;
    st.push(temp);

    while(!st.empty()){
        temp = st.top();
        st.pop();
        ans.push_back(temp->key);

        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }

    }
}

// Recursive Approach:

void preorderRecursive(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->key);
        preorderRecursive(root->left, ans);
        preorderRecursive(root->right, ans);
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
    // preorderRecursive(root, ans);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    preorderIterative(root, ans);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}