// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs1(vector<int> adj[], stack<int>& st, int i, vector<bool> & vis){
	    vis[i] = true;
	    
	    for(auto it:adj[i]){
	        if(!vis[it]) dfs1(adj, st, it, vis);
	    }
	    
	    st.push(i);
	}
	
	void dfs2(vector<int> adj[], vector<bool>& vis, int i){
	    vis[i] = true;
	    
	    for(auto it:adj[i]){
	        if(!vis[it]) dfs2(adj, vis, it);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i=0; i<V; ++i){
            if(!vis[i]) dfs1(adj, st, i, vis);
        }
        
        vector<int> rev[V];
        for(int i=0; i<V; ++i){
            for(auto it:adj[i]){
                rev[it].push_back(i);
            }
        }
        
        vis.clear();
        vis.resize(V, false);
        
        int cnt = 0;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            
            if(!vis[curr]){
                cnt++;
                dfs2(rev, vis, curr);
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends