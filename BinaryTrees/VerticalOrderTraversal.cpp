// PROBLEM: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/


#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    // Here there can be multiple verticals(horizontal distance) from root(-2,-1,0,1,2)
    // and at each vertical, there can be multiple levels(0,1,2,3...)
    // and in each level, there can be multiple nodes

    queue<pair<TreeNode*, pair<int, int>>> q; // {node, {distance, level}}
    q.push({root,{0, 0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int d = p.second.first;
        int l = p.second.second;

        mp[d][l].insert(node->val);

        if(node->left){
            q.push({node->left, {d-1, l+1}});;
        }
        if(node->right){
            q.push({node->right, {d+1, l+1}});
        }
    }

    vector<vector<int>> ans;

    for(auto p: mp){
        vector<int> temp;
        for(auto q: p.second){
            // insert function inserts all the elements before specified position for a given range
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    return 0;
}