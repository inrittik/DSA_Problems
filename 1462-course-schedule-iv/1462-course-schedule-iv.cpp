class Solution {
public:
    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> indegree(N);
        unordered_map<int, set<int>> g;
        unordered_map<int, set<int>> mp;
        
        for (auto it: pre) {
            indegree[it[1]]++;
            g[it[0]].insert(it[1]);
        }
        
        queue<int> q;
        for(int i=0; i<N; ++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : g[node]) {
                mp[next].insert(node);
                mp[next].insert(mp[node].begin(), mp[node].end());
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        vector<bool> ans;
        for (auto pair : queries) {
            if (mp[pair[1]].find(pair[0])!=mp[pair[1]].end()) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};