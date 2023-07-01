// Problem:
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};


// Method 1: By pushing NULL nodes into queue using Level Order Traversal

bool isSymmetric(Node* root) {
        queue<Node*> q;
        q.push(root);

        vector<int> temp;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node==NULL){
                    temp.push_back(INT_MIN);
                }
                else temp.push_back(node->val);

                if(node!=NULL){
                    if(node->left!=NULL){
                        q.push(node->left);
                    }
                    else{
                        q.push(NULL);
                    }
                    if(node->right!=NULL){
                        q.push(node->right);
                    }
                    else{
                        q.push(NULL);
                    }
                }
                else{
                    q.push(NULL);
                    q.push(NULL);
                } 
            }
            vector<int>v1(temp.size(), INT_MIN);
            if(temp==v1){
                // if we have pop the nodes of the last level then we have only NULL nodes in our queue
                // and INT_MIN corresponding to those NULL nodes in temp, so we exit from the while loop
               break;
            }
            vector<int> rev = temp;
            reverse(temp.begin(), temp.end());
            if(temp!=rev){
                return false;
            }
            temp.clear();
        }

        return true;
    }
// *********** M2: 


bool helper(Node* l, Node* r){
    if(l==NULL || r==NULL){
        // Both of them must be null
        return l==r;
    }

//      If both left and right nodes are not NULL then:
    if(l->val != r->val){
        return false;
    }

    return (helper(l->left, r->right) && helper(l->right, r->left));
}
bool isSymmetric(Node* root) {
    return helper(root->left, root->right);
}

int main()
{
    return 0;
}