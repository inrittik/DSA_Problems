class Solution {
public:
    void dfs(vector<vector<int>>& revEdges, int i, vector<bool>& vis){
        vis[i] = true;
        for(auto it:revEdges[i]){
            if(!vis[it]) dfs(revEdges, it, vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> revEdges(n);
        for(auto i:edges){
            revEdges[i[1]].push_back(i[0]);
        }
        
        vector<vector<int>> ansList(n);
        
        for(int i=0; i<n; ++i){
            vector<bool> vis(n, false);
            vector<int> ancestors;
            dfs(revEdges, i, vis);
            for(int j=0; j<n; ++j){
                if(vis[j] && i!=j){
                    ancestors.push_back(j);
                }
            }
            ansList[i] = ancestors;
        }
        
        return ansList;
    }
};