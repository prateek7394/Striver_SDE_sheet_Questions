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

vector<int> topView(Node *root)
    {
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
            
            if(m.find(dist)==m.end()){
            // add a pair to the map only for the first time to avoid updating its value by lower nodes at same horizontal distance
                m[dist] = node;
            }
            
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