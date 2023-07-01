// PROBLEM:
// Find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

#include<bits/stdc++.h>
using namespace std;

struct Node {
int key;
Node *left;
Node *right;
Node(int x) : key(x), left(NULL), right(NULL) {}
};

// ********** M1: (Naive Approach by storing inorder traversal in a vector)

void inorder(Node* root, vector<Node*> &v){
    if(root == NULL) return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<Node*> v;
    inorder(root, v);
    int n = v.size();
    int i=0;
    
    while(i<n && v[i]->key < key){
        i++;
    }
    
    if(i==0){
        if(v[i]->key == key){
            pre = NULL;
            suc = v[i+1];
        }
        else{
            pre = NULL;
            suc = v[i];
        }
    }

    else if(i==n-1){
        if(v[i]->key==key){
            pre = v[i-1];
            suc = NULL;
        }
        else{
            pre = v[i-1];
            suc = v[i];
        }
    }
        
    else if(i==n){
        pre = v[i-1];
        suc = NULL;
    }
    
    else if(v[i]->key==key){
        pre = v[i-1];
        suc = v[i+1];
    }
    
    else{
        pre = v[i-1];
        suc = v[i];
    }
    
}

// ******************* M2: Find first value > key and last value < key while doing inorder traversal

void inorder(Node* root, int &key, Node* &pre, Node* &suc, bool &flag){
        if(root==NULL){
            return;
        }
        inorder(root->left, key, pre, suc , flag);
        if(root->key > key ){
            if(flag==0){
                // update suc only for first value >  key
                flag = 1;
                suc = root;
            }
        }
        else if(root->key< key){
            // pre is continuosly updated till last value < key is found
            pre = root;
        }
        
        inorder(root->right, key, pre, suc , flag);
    }
    
    
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    bool flag = 0;
    inorder(root, key, pre, suc, flag);        
}

// ***************** M3: Optimal Approach *********************
// T=O(H), S.C= O(1) 


// Recursive:
void successor(Node* root, Node* &s, int &key){
        if(root==NULL){
            return;
        }
        
        if(root->key > key){
            s = root;
            successor(root->left, s, key);
        }
        else{
            successor(root->right, s, key);
        }
    }
    
void predecessor(Node* root, Node* &p, int &key){
    if(root==NULL){
        return;
    }
    
    if(root->key < key){
        p = root;
        predecessor(root->right, p, key);
    }
    else{
        predecessor(root->left, p, key);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    suc=NULL, pre=NULL;
    successor(root, suc, key);
    predecessor(root, pre, key);

    // Iterative:
    // while(root!=NULL){
    //     if(key>= root->key){
    //         root = root->right;
    //     }
    //     else{
    //         suc = root;
    //         root = root->left;
    //     }
    // }

}

int main()
{
    return 0;
}