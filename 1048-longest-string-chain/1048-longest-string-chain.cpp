class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        unordered_map<string, int> mp;
        int mxLen = 1;
        for(int i=0; i<n; ++i){
            mp[words[i]] = 1;
            int s = words[i].size();
            for(int c=0; c<s; ++c){
                string word = words[i].substr(0, c)+words[i].substr(c+1);
                if(mp.find(word)!=mp.end()){
                    mp[words[i]] = max(mp[words[i]], mp[word] + 1);
                    mxLen = max(mxLen, mp[words[i]]);
                }
            }
        }
        
        return mxLen;
    }
};