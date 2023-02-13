#include <bits/stdc++.h> 



vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> in(v,0);
    unordered_map<int,list<int>> adj;
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
        in[i[1]]++;
    }
    queue<int> q;
    for(int i = 0;i< v ;i++) if(in[i] == 0) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(int i : adj[temp]){
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
    }
    return ans;

}
