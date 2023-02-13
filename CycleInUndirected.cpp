#include<bits/stdc++.h>

// bool dfs(int i,int parnode,unordered_map<int,set<int>> &adj,vector<bool> &vis,
// unordered_map<int,int> &par){
//     // if(vis[i] && par[i] != parnode) return true;
//     vis[i] = true;
//     for(int j : adj[i]){
//         if(!vis[j]){
//             par[j] = i;
//             if(dfs(j,i,adj,vis,par)) return true;
//         }
//         else if(j != par[i]) return true;

//     }
//     vis[i] = false;
//     return false;
// }


bool bfs(int node,unordered_map<int,set<int>> &adj,vector<bool> &vis){
    queue<int> q;
    unordered_map<int,int> par;
    par[node] = -1;
    vis[node] = true;
    q.push(node);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        int currnode = temp;
        for(int i : adj[temp]){
         if(vis[i] && par[temp] != i) return true;
         else if(!vis[i]){
             par[i] = temp;
             vis[i] = true;
             q.push(i);
         }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,set<int>> adj;
    // unordered_map<int,int> par;
    for(auto i : edges){
        adj[i[0]].insert(i[1]);
        adj[i[1]].insert(i[0]);
    }
    vector<bool> vis(n+1,false);
    for(int i =1 ;i<=n;i++){
        if(!vis[i] && bfs(i,adj,vis)) return "Yes";
    }
    return "No";
}
