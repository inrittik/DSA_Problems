class Solution {
public:
    void getPath(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& paths){
        if(node==graph.size()-1){
            path.push_back(node);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node);
        for(auto it:graph[node]){
            getPath(graph, it, path, paths);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        getPath(graph, 0, path, paths);
        return paths;
    }
};