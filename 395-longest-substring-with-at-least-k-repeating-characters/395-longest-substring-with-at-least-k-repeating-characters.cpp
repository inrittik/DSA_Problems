class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n==0 || k>n) return 0;
        
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        
        int idx = 0;
        while(idx<n && mp[s[idx]]>=k) idx++;
        if(idx==n) return n;
        
        int left = longestSubstring(s.substr(0,idx), k);
        int right = longestSubstring(s.substr(idx+1), k);
        
        return max(left, right);
    }
};