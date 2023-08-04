// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[][] of length M,
// where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, 
// then return -1 for that vertex.



// ********************* M1: Using TopoSort **********************
#include<bits/stdc++.h>
using namespace std;

//  helper function
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
//  main function
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Create adjacency list for each vertex adj[u] = {v, wt}
        vector<pair<int, int>> adj[N];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
        }
        
        // Perform TopoSort:
        vector<int> vis(N, 0);
        stack<int> st;
        
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        // declare the distance vector
        vector<int> dis(N, INT_MAX);
        dis[0]=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(dis[node]!=INT_MAX){
                for(auto it: adj[node]){
                    int adjNode = it.first;
                    int edgeWt = it.second;
                    
                    if(dis[node]+edgeWt < dis[adjNode]){
                        dis[adjNode] = dis[node]+edgeWt;
                    }
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dis[i]==INT_MAX){
                dis[i] = -1;
            }
        }
        
        return dis;
    }

// ********************* M1: Using Dijkstra's Algorithm **********************

typedef pair<int, int> pi;
  
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // Create adjacency list for each vertex adj[u] = {v, wt}
    vector<pair<int, int>> adj[N];
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        adj[u].push_back({v, wt});
    }
    
    // Declare Priority Queue:
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    // declare the distance vector:
    vector<int> dis(N, INT_MAX);
    dis[0]=0; // here the src vertex is 0
    pq.push({0, 0}); //{distance, node}
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            
            if(dis[node]+edgeWt < dis[adjNode]){
                dis[adjNode] = dis[node]+edgeWt;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    
    for(int i=0; i<N; i++){
        if(dis[i]==INT_MAX){
            dis[i] = -1;
        }
    }
    
    return dis;
}

int main()
{
    return 0;
}