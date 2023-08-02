#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    vector<int> vis(V, 0);
    vector<int> ans;
    ans.push_back(0);
    q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                ans.push_back(it);
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