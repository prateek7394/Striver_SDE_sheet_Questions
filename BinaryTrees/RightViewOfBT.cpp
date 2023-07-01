#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

// ************ M1: Iterative solution(Using NULL)

vector<int> rightView(Node *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
   ans.push_back(root->data);

   queue<Node*> q;
   q.push(root);
   q.push(NULL); // Add NULL at the end of each level
   
   while(q.size()>1){
       Node* curr = q.front();
       q.pop();
       
       if(curr==NULL){
           q.push(NULL);
           Node* front = q. front();
           ans.push_back(front->data);
           continue;
       }
       
    //    First push the right child then push the left child into the queue
       if(curr->right!=NULL){
           q.push(curr->right);
       }

       if(curr->left!=NULL){
           q.push(curr->left);
       }
       
       
   }
   
   return ans;
}

// *********** M2: Recursive Solution using Preorder traversal & 2 variables
int maxLevel = 0;

void RVRecursive(Node* root, int level, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(level>maxLevel){
        ans.push_back(root->data);
        maxLevel = level;
    }

    RVRecursive(root->right, level+1, ans);
    RVRecursive(root->left, level+1, ans);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(5);
    root->left->right = new Node(30);
    root->right->left = new Node(7);
    root->right->right = new Node(6);

    vector<int> ans;
    RVRecursive(root, 1, ans);

    for(auto ele: ans){
        cout<<ele<<" ";
    }
    return 0;
}