#include<bits/stdc++.h>>

bool dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &vis,vector<bool> &dfsvis){

    vis[node] = 1;
    dfsvis[node] = 1;
    for(int neigh: adj[node]){
        if(!vis[neigh] && dfs(neigh,adj,vis,dfsvis)){
            return true;
        }
        else if(dfsvis[neigh]) return true;
    }

    dfsvis[node] = 0;
    return false;
}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(auto i : edges){
      adj[i.first].push_back(i.second);
    }
    vector<bool> vis(n+1,false),dfsvis(n+1,false);
    for(int i = 1; i<= n ; i++){
        if(!vis[i] && dfs(i,adj,vis,dfsvis)) return true;
    }
    return false;
}
