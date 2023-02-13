class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        vector<int> in(n); 
        for(auto i: edges){
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int> q;
        vector<int> topo;
        for(int i =0 ;i<n;i++) if(in[i] == 0) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            topo.push_back(temp);
            for(auto neigh : adj[temp]){
                in[neigh]--;
                if(in[neigh] == 0) q.push(neigh);
            }
        }
        if(topo.size() == n) return topo;
        return {};
    }
};
