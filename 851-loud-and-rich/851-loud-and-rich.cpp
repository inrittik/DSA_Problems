class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> indegree(n);
        unordered_map<int, set<int>> g;
        
        for (auto it: richer) {
            indegree[it[1]]++;
            g[it[0]].insert(it[1]);
        }
        
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans(n);
        for(int i=1; i<n; ++i){
            ans[i] = ans[i-1]+1;
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : g[node]) {
                if (quiet[ans[next]] > quiet[ans[node]]) {
                    ans[next] = ans[node];
                }
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return ans;
    }
};