class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        int n = equations.size();
        
        for(int i=0; i<n; ++i){
            mp[equations[i][0]].insert({equations[i][0], 1.0});
            mp[equations[i][1]].insert({equations[i][1], 1.0});
            mp[equations[i][0]].insert({equations[i][1], values[i]});
            mp[equations[i][1]].insert({equations[i][0], 1/values[i]});
        }
        
        vector<double> ans;
        for(auto k:mp){
            for(auto i:mp){
                for(auto j:mp){
                    if (mp[i.first].count(j.first) == 0)
                    {
                        if (mp[i.first].count(k.first) && mp[k.first].count(j.first))
                        {
                            mp[i.first].insert({j.first, mp[i.first][k.first]*mp[k.first][j.first]});
                        }
                    }
                }
            }
        }
        
        for(auto q:queries){
            if (mp.count(q[0]) && mp[q[0]].count(q[1]))
            {
                ans.push_back(mp[q[0]][q[1]]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};