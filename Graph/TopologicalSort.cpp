// TOPOLOGICAL SORT:
// -> Exists only for DAG
// -> If there exists an edge from u to v, then u must appear before v in the linear order

#include<bits/stdc++.h>
using namespace std;

// *********************** M1: Using Stack(DFS Approach) ****************

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    
    st.push(node);
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

// ***************************** M2: Using BFS(Kahn's Algorithm) ********************



int main()
{
    return 0;
}