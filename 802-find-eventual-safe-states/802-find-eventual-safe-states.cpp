class Solution {
public:
    bool inCycle(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsVis){
        vis[i]=1;
        dfsVis[i]=1;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(inCycle(it, adj, vis, dfsVis)) return true;
            }
            else if(dfsVis[it]) return true;
        }
        
        dfsVis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<int> dfsVis(n);
        
        vector<int> safe;
        
        for(int i=0; i<n; ++i){
            if(!inCycle(i, graph, vis, dfsVis)) safe.push_back(i);
        }
        
        return safe;
    }
};