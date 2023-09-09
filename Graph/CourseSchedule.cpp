// PROBLEM: https://leetcode.com/problems/course-schedule/description/
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
// course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// ----------- APPROACH ------------------
// Here we have to basically check whether there exists a cycle in the graph of courses(directed graph) or not
// E.g. If prerequisites = {{0,1}, {1,2}, {2,0}} it means are courses are interdependent i.e. graph contains cycle
// So, we cannot finish all the courses.

#include<bits/stdc++.h>
using namespace std;

// --------------------------M1(Using vis & pathVis array) ------------------
// T.C = O(V+E)

bool dfsCheck(int node, vector<vector<int>> &adj, vector<int>&vis, vector<int>&pathVis){
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
        // on the same path
            return true;
        }
    }
    
    pathVis[node]=0;
    // when there are no recursion calls left and we are returning back
    // we unmark pathVis for all the nodes in backward path
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Here numCourses represent no. of nodes from 0 till numCourses-1

    // create the adjacency list
    vector<vector<int>> adj(numCourses);
    for(auto it: prerequisites){
        int u = it[0];
        int v = it[1];

        // directed edge from v to u since course u can be taken only 
        // after course v is finished
        adj[v].push_back(u);
    }

    vector<int>vis(numCourses, 0);
    vector<int>pathVis(numCourses, 0);

    // check for all components of graph
    for(int i=0; i<numCourses; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathVis)==true) return false;
            // if cycle exists implies we cannot complete all courses, 
            // so return false
        }
    }

    return true;
}

// ----------------------------- M2(Using Kahn's Algorithm) ---------------------
// T.C = O(V+E)

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Here numCourses represent no. of nodes from 0 till numCourses-1

    // create the adjacency list
    vector<vector<int>> adj(numCourses);
    for(auto it: prerequisites){
        int u = it[0];
        int v = it[1];

        // directed edge from v to u since course u can be taken only 
        // after course v is finished
        adj[v].push_back(u);
    }

    vector<int>indegree(numCourses, 0);
    for(int i=0; i<numCourses; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }

    queue<int>q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return count==numCourses;
}

int main()
{
    return 0;
}