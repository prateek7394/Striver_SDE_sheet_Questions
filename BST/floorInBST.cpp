#include<bits/stdc++.h>
using namespace std;

struct Node {
int val;
Node *left;
Node *right;
Node(int x) : val(x), left(NULL), right(NULL) {}
};

int floorInBST(Node * root, int X)
{
    int ans = -1;
    
    while(root!=NULL){
        if(root->val == X){
            return X;
        }
        else if(root->val < X){
            ans = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }

    return ans;
}

int main()
{
    return 0;
}