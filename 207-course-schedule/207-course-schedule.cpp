class Solution {
public:
    vector<int> vis;
    bool cyclic(int node, int par, vector<vector<int>>& graph){
        vis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(cyclic(it, node, graph)) return true;
            }
            else if(vis[it]==1){
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        vis.resize(numCourses+1, 0);
        for(int i=0; i<numCourses; ++i){
            if(!vis[i]){
                if(cyclic(i, -1, graph)){
                    return false;
                }
            }
        }
        
        return true;
    }
};