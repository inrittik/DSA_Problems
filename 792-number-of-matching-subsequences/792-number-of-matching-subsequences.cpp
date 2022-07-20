class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> mp(128);
        for(int i=0; i<n; ++i){
            mp[s[i]].push_back(i);
        }
        int cnt = 0;
        for(auto &word:words){
            int curr_idx = -1;
            int flag = 1;
            
            for(int i=0; i<word.size(); ++i){
                auto it = upper_bound(mp[word[i]].begin(), mp[word[i]].end(), curr_idx);
                if(it==mp[word[i]].end()) flag = 0;
                else curr_idx = *it;
            }
            
            if(flag) cnt++;
        }
        return cnt;
    }
};