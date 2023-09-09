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

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> indegree(V, 0);
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
        }   
    }
    
    queue<int> q;
    for(int i=0; i<V; i++){
        // Push all nodes having indegree=0 into the queue since nodes having no incoming edges can be
        // placed at the beginnning of linear ordering
        if(indegree[i]==0) q.push(i);
    }
    
    vector<int> ans;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node); // add the node into ans
        
        for(auto it: adj[node]){
            // When a node is popped(removed) from graph, the indegree of its adjacent nodes reduces by 1
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    
    return ans;
}


int main()
{
    return 0;
}