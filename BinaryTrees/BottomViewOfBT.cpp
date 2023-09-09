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

vector <int> bottomView(Node *root) {
    // Bottom view includes all the nodes which can be seen from bottom at every possible hd(even 0) from root
    // hd represents horizontal distance from root  
    vector<int>ans;         
    if(root==NULL){ 
        return ans;
    }
    queue<pair<Node*, int>> q; // {node, hd} 
    q.push({root, 0});
    
    map<int, Node*> m; // {hd, node}
    
    while(!q.empty()){
        Node* node = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        m[dist] = node;
        
        if(node->left!=NULL){
            q.push({node->left, dist-1});
        }
        
        if(node->right!=NULL){
            q.push({node->right, dist+1});
        }
    }
    
    
    for(auto it: m){
        ans.push_back(it.second->data);
    }
    
    return ans;
}


int main()
{
    return 0;
}