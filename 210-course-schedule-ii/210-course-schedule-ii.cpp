class Solution {
public:
    vector<int> topo;
    void dfs(int i, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj){
	    vis[i]=1;
	    
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(it, vis, st, adj);
	        }
	    }
	    st.push(i);
	}
    
    bool check_cycle(stack<int>& st, vector<vector<int>>& adj, int V){
        unordered_map<int, int> pos;
        int index = 0;
        while (!st.empty()) {
            pos[st.top()] = index;
            topo.push_back(st.top());

            index += 1;
            st.pop();
        }

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {

                if (pos[i] > pos[it]) {
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> rev(V);
        for(auto it:prerequisites){
            rev[it[1]].push_back(it[0]);
        }
        
        stack<int> st;
        vector<int> vis(V);
	    
	    for(int i=0; i<V; ++i){
	        if(!vis[i]){
	            dfs(i, vis, st, rev);
	        }
	    }
        vector<int> empty;
        if(check_cycle(st, rev, V)) return empty;
	    return topo;
    }
};