class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> v(26, vector<int>(2,-1));
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(v[s[i]-'a'][0]==-1){
                v[s[i]-'a'][0] = i;
                v[s[i]-'a'][1] = i;
            }
            else{
                v[s[i]-'a'][1] = i;
            }
        }
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        res.push_back(v[0]);
        for(int i=0; i<26; ++i){
            if (res.back()[1] < v[i][0]) res.push_back(v[i]);
            else res.back()[1] = max(res.back()[1], v[i][1]);
        }
        vector<int> ans;
        for(int i=0; i<res.size(); ++i){
            ans.push_back(res[i][1]-res[i][0]+1);
        }
        if(ans[0]==1) ans.erase(ans.begin());
        return ans;
    }
};