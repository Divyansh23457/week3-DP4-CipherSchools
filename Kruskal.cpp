#include<bits/stdc++.h>

bool cmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
} 

int findParent(vector<int> &par,int node){
    if(par[node] == node) return node;
    return par[node] = findParent(par,par[node]);
}

void set_union(int u,int v,vector<int> &rank,vector<int> &par){
    if(rank[u] > rank[v]){
        par[v] = u;
        rank[u]++;
    }
    else {
        par[u] = v;
        rank[v]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> par(n+1);
    for(int i=0 ;i<n;i++) par[i] = i;
    vector<int> rank(n+1,0);
    int ans =0 ;
    for(edge : edges){
        int u = findParent(par,edge[0]);
        int v = findParent(par,edge[1]);
        int w = edge[2];
        if(u != v){
            ans += w;
            set_union(u,v,rank,par);
        }
    }
    return ans;
}
