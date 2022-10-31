class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int mx = 0;
        for(auto r:matrix){
            string s = "";
            bool complement = false;
            if(r[0]==1) complement = true;
            for(int x:r){
                if(complement) s+= to_string(x^1);
                else s+= to_string(x);
            }
            mx = max(mx, ++mp[s]);
        }
        return mx;
    }
};