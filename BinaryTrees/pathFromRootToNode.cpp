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

bool path(Node* root, vector<int> &ans, int x){
	if(root==NULL){
        // means target node not found 
		return false;
	}

	ans.push_back(root->data); // keep pushing the nodes into the list
	if(root->data==x){
        // means target is found 
		return true;
	}

	bool leftCall = path(root->left,ans,x);
	bool rightCall = path(root->right,ans,x);

	if((leftCall || rightCall)==false){
        // If both left and right call doesn't find the target node, pop the last added node (as we followed the wrong path) and return false to parent function call
		ans.pop_back();
		return false;

	}
	return true; // if any of left and right call return true, then return true to parent function call

}

vector<int> pathInATree(Node*root, int x) {
  vector<int> ans;
  path(root, ans, x);
  return ans;
}

int main()
{
    return 0;
}