class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> inDegree(n);
        vector<int> ans;
        
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(inDegree[i]==1) q.push(i);
        }
        
        int cnt = n;
        while(cnt>2){
            int sz = q.size();
            cnt -= sz;
            while(sz-->0){
                int node = q.front();
                q.pop();
                for(int ad:g[node]){
                    if(--inDegree[ad]==1){
                        q.push(ad);
                    }
                }
            }
        }
        
        
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};