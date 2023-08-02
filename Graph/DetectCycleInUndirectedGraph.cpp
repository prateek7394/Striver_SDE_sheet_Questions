#include<bits/stdc++.h>
using namespace std;

// ******************** M1: Using BFS ****************************

bool detectLoop( int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});
            }
            
            else if(vis[adjacentNode] && adjacentNode!=parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    // To check for all connected components of graph
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detectLoop(i,adj,vis))
            return true;
        }
    }
    return false;
}

// ******************** M1: Using DFS ****************************

bool detectCycle(int node, int parent, vector<int>adj[], vector<int> &vis){
    vis[node] = 1;
    
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(detectCycle(adjNode, node, adj, vis)==true){
                return true;
            }
        }
        else if(vis[adjNode] && adjNode!=parent){
            return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detectCycle(i, -1, adj, vis)==true){
                return true;
            }
        }   
    }
    return false;
}


int main()
{
    return 0;
}