#include <bits/stdc++.h> 

void dfs(int node,vector<bool> &vis,stack<int> &s,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(int neigh : adj[node]){
        if(!vis[neigh]) dfs(neigh,vis,s,adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<bool> vis(v,false);
    unordered_map<int,list<int>> adj;
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
    }
    stack<int> s;
    for(int i =0 ;i < v;i++){
        if(!vis[i])dfs(i,vis,s,adj);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
