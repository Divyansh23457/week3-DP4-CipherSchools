//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void dfs(char c,unordered_map<char,list<char>> &adj,unordered_map<char,bool> &vis,stack<char> &s){
        vis[c] = true;
        for(char neigh : adj[c]){
            if(!vis[neigh]) dfs(neigh,adj,vis,s);
        }
        s.push(c);
    }
    
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,list<char>> adj;
        for(int i =0 ;i < N-1;i++){
            int j = 0,k = 0;
            while(j < dict[i].length() && k < dict[i+1].length()){
                if(dict[i][j] != dict[i+1][k]){
                    adj[dict[i][j]].push_back(dict[i+1][k]);
                    break;
                }
                k++;
                j++;
            }
        }
        unordered_map<char,bool> vis;
        stack<char> s;
        for(int i = 0 ;i < K;i++){
            char c = (char)(i+97);
            if(!vis[c]){
                dfs(c,adj,vis,s);
            }
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
