class Solution {
public:


    bool dfs(int node,vector<bool> &vis,vector<bool> &dfsvis,unordered_map<int,list<int>> &adj){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto neigh : adj[node]){
            if(!vis[neigh] && dfs(neigh,vis,dfsvis,adj)) return true;
            else if(dfsvis[neigh]) return true;
        }
        dfsvis[node] =false;
        return false;

    }
 
    bool canFinish(int n, vector<vector<int>>& edges) {
     unordered_map<int,list<int>> adj;
     for(auto i : edges){
         adj[i[1]].push_back(i[0]);
     }   
     vector<bool> vis(n,false),dfsvis(n,false);
     for(int i =0 ;i<n;i++){
         if(!vis[i] && dfs(i,vis,dfsvis,adj)) return false;
     }
        return true;
    }
};
