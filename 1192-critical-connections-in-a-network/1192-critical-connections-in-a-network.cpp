class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, int par, vector<int>& time, vector<int>& bestTime, vector<bool>& vis, int& timer, vector<vector<int>>& ans){
        vis[node]=true;
        time[node] = bestTime[node] = timer++;
        
        for(auto it:adj[node]){
            if(it==par) continue;
            
            if(!vis[it]){
                dfs(adj, it, node, time, bestTime, vis, timer, ans);
                bestTime[node] = min(bestTime[node], bestTime[it]);
                if(bestTime[it]>time[node]){
                    vector<int> temp;
                    temp.push_back(it);
                    temp.push_back(node);
                    ans.push_back(temp);
                }
            }
            else{
                bestTime[node] = min(bestTime[node], bestTime[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> time(n), bestTime(n);
        vector<vector<int>> ans;
        
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        int timer=0;
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                dfs(adj, i, -1, time, bestTime, vis, timer, ans);
            }
        }
        
        return ans;
    }
};