class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> mp;
        int res=1;
        for(string s:words){
            mp[s] = 1;
            for(int i = 0; i < s.size(); i++) {
                string prev = s.substr(0, i) + s.substr(i + 1);
                if (mp.find(prev) != mp.end()) {
                    mp[s] = mp[prev] + 1;
                    res = max(res, mp[s]);
                }
            }
        }
        return res;
    }
};