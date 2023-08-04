// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj 
// where adj[i] is a list of lists containing two integers where the first integer of each list j denotes 
// there is edge between i and j , second integers corresponds to the weight of that  edge . 
// You are given the source vertex S and You have to Find the shortest distance of all the vertex's 
// from the source vertex S. You have to return a list of integers denoting shortest distance between each node
// and Source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Declare Priority Queue:
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    // declare the distance vector:
    vector<int> dis(V, INT_MAX);
    dis[S]=0; // here the src vertex is 0
    pq.push({0, S}); //{distance, node}
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];
            
            if(dis[node]+edgeWt < dis[adjNode]){
                dis[adjNode] = dis[node]+edgeWt;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    
    return dis;
}

int main()
{
    return 0;
}