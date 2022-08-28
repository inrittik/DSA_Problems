class Solution {
public:
    bool topoSort(vector<vector<int>>& adj,int k, vector<int>& topo){
        vector<int> in_deg(k+1);
        for(int i=0; i<adj.size(); ++i){
            for(auto it:adj[i]) in_deg[it]++;
        }
        
        queue<int> q;
        for(int i=1; i<=k; ++i){
            if(in_deg[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            topo.push_back(node);
            for(auto it:adj[node]){
                in_deg[it]--;
                if(in_deg[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==k;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> row(k+1);
        vector<vector<int>> col(k+1);
        
        for(auto it:rowConditions){
            row[it[0]].push_back(it[1]);
        }
        for(auto it:colConditions){
            col[it[0]].push_back(it[1]);
        }
        
        vector<int> topoRow;
        vector<int> topoCol;
        bool tR = topoSort(row, k, topoRow);
        bool tC = topoSort(col, k, topoCol);
        vector<vector<int>> ans;
        if(!tR || !tC) return ans;
        
        ans.resize(k, vector<int>(k));
        for(int i=0; i<k; ++i){
            int num = topoRow[i];
            int c = 0;
            for(int j=0; j<k; ++j){
                if(topoCol[j]==num){
                    c = j;
                    break;
                }
            }
            ans[i][c]=num;
        }
        return ans;
    }
};