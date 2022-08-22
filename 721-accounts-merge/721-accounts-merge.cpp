class Solution {
public:
    unordered_map<string, string> par;
    vector<vector<string>> ans;
    void bfs(unordered_map<string, vector<string>>& rel, unordered_map<string,int>& vis, set<string>& s, string node){
        queue<string> q;
        q.push(node);
        vis[node]++;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                s.insert(curr);
                q.pop();
                for(auto str:rel[curr]){
                    if(!vis[str]){
                        vis[str]++;
                        q.push(str);
                    }
                }
            }
        }
        vector<string> fin;
        fin = vector(s.begin(), s.end());
        fin.insert(fin.begin(), par[*s.begin()]);
        ans.push_back(fin);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto account:accounts){
            for(int i=1; i<account.size(); ++i){
                par[account[i]] = account[0];
            }
        }
        
        unordered_map<string, vector<string>> rel;
        for(auto account:accounts){
            int sz = account.size();
            for(int i=1; i<sz; ++i){
                for(int j=i+1; j<sz; ++j){
                    rel[account[i]].push_back(account[j]);
                    rel[account[j]].push_back(account[i]);
                }
            }
        }
        unordered_map<string,int> vis;
        for(auto account: accounts){
            set<string> osf;
            if(!vis[account[1]]) bfs(rel,vis,osf,account[1]);
        }
        return ans;
    }
};