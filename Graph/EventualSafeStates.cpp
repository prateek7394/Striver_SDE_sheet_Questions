// PROBLEM: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include<bits/stdc++.h>
using namespace std;

// APPROACH:
// A node cannot be safe node if:
// 1. It is a part of a cycle
// 2. It has a path that leads to a cycle

bool dfsCheck(int node, vector<int>&vis, vector<int>&pathVis, vector<int> adj[], 
vector<int>&check){
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it, vis, pathVis, adj, check)==true){
                check[node]=0; // if we found a path from a node that leads to a cycle , then mark that node as not safe
                return true;
            }
        }
        else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    
    check[node] = 1; // if we do not get a cycle even after visiting 
    // all possible paths from a node, mark it safe.
    pathVis[node]=0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> ans;
    
    vector<int>vis(V, 0);
    vector<int>pathVis(V, 0);
    vector<int>check(V, 0); // to mark a node safe or not safe
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfsCheck(i, vis, pathVis, adj, check);
        }
    }
    
    for(int i=0; i<V; i++){
        if(check[i]==1) ans.push_back(i);
    }
    
    return ans;
}

int main()
{
    return 0;
}