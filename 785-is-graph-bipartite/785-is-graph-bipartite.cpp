class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph, vector<int>& color, int i){
        if(color[i]==-1) color[i]=1;
        
        for(auto it: graph[i]){
            if(color[it]==-1){
                color[it] = 1-color[i];
                
                if(!isBipartite(graph, color, it)) return false;
            }
            else if(color[it]==color[i]) return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; ++i){
            if(color[i]==-1){
                if(!isBipartite(graph, color, i)) return false;
            }
        }
        return true;
    }
};