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
// M1--> Using single stack but reversing the vector(Equivalent to 2 stack method)

void postorderIterative1(Node* root, vector<int> &ans){
    if(root == NULL){
            return;
        }

        Node *temp = root;
        stack<Node*> st;
        st.push(temp);

        while(!st.empty()){
            temp = st.top();
            st.pop();
            ans.push_back(temp->key);

            if(temp->left!=NULL){
                st.push(temp->left);
            }

            if(temp->right!=NULL){
                st.push(temp->right);
            }
        }

        reverse(ans.begin(), ans.end());
}

// M2--> Using single stack without reversing(if asked to directly print without storing anywhere)

vector < int > postorderIterative2(Node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < Node * > st;
  while (cur != NULL || !st.empty()) {
    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } 
    else {
      Node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> key);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> key);
        }
      } 
      else 
        cur = temp;
    }
  }
  return postOrder;

}

// Recursive Approach:

void postorderRecursive(Node* root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    postorderRecursive(root->left, ans);
    postorderRecursive(root->right, ans);
    ans.push_back(root->key);
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
    postorderRecursive(root, ans);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    // postorderIterative(root, ans);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
    return 0;
}