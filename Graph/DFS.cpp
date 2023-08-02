#include<bits/stdc++.h>
using namespace std;

void helper(int node, vector<int> &ans, vector<int> &vis, vector<int>adj[]){
    vis[node] = 1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            helper(it, ans, vis, adj);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    int startNode = 0;
    vector<int> vis(V, 0);
    helper(startNode, ans, vis, adj);
    return ans;
}

int main()
{
    return 0;
}