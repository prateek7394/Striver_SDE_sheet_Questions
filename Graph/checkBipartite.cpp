// PROBLEM:
// A graph is Bipartite, if all the vertices of the graph can be colored using two different colors, such that
// no two adjacent vertices have same color.



#include<bits/stdc++.h>
using namespace std;

// ****************************** M1: Using bfs *******************************

bool bfs(int startNode, vector<int> color, vector<vector<int>>& graph){
    color[startNode] = 1;

    queue<int> q;
    q.push(startNode);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: graph[node]){
            if(color[it]==-1){
                color[it] = !color[node]; 
                // if node is 0, then adjNode = 1 & vice-versa
                q.push(it);
            }
            else if(color[it] == color[node]){
                // if two adjacent nodes have same color
                return false;
            }
        }
    }

    return true;
    
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(bfs(i, color, graph)==false) return false;;
        }
    }
    return true;
}

// ****************************** M1: Using dfs *******************************

bool dfs(int node, int col, vector<int> &color, vector<vector<int>>& graph){
    color[node]=col;
    for(auto it: graph[node]){
        if(color[it]==-1){
            if(dfs(it, !col, color, graph) == false){
                return false;
            }
        }
        else if(color[it]==color[node]){
            return false;
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(dfs(i,0,color, graph)==false) return false;;
        }
    }
    return true;
}


int main()
{
    return 0;
}