class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()) return false;
        unordered_map<char, int> mp;
        for(char c:s) mp[c]++;
        int odd = 0;
        for(auto it: mp) if(it.second%2!=0) odd++;
        return odd<=k;
    }
};