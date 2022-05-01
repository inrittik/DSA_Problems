// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<int> vis;
  public:
    // Function to detect cycle in a directed graph.
    bool cycleDFS(int node, int par, vector<int> adj[]){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(cycleDFS(it, node, adj)) return true;
            } 
            else if(vis[it]==1){
                return true;
            }
        }
        
        vis[node] = 2;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vis.resize(V+1, 0);
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(cycleDFS(i, -1, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends