#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int>adj[], vector<int>&vis, vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it, adj, vis, pathVis)==true) return true;
            // if any of the recursion calls return true, then no need to check
            // for other neighbours
        }
        else if(pathVis[it]){
        // if the node has been previously visited and it is visited
        // on the same path means we came back to same point that we have already visited along same path
        // => cycle exists
            return true;
        }
    }
    
    pathVis[node]=0;
    // when there are no recursion calls left and we are returning back
    // we unmark pathVis for all the nodes in backward path
    return false;
}


bool isCyclic(int V, vector<int> adj[]) {
    vector<int>vis(V, 0);
    vector<int>pathVis(V, 0); // stores whether a node has been visited by same path or not
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathVis)==true) return true;
        }
    }
    
    return false;
}

int main()
{
    return 0;
}