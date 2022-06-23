class Solution {
public:
    unordered_map<string, bool> mp;
    bool helper(string s1, string s2){
        string s = s1+" "+s2;
        
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        if(s1.size()<=1) return false;

        if(mp.find(s)!=mp.end()) return mp[s];
        int n = s1.size();
        for(int k=1; k<=n-1; ++k){
            if(helper(s1.substr(0,k), s2.substr(n-k)) && helper(s1.substr(k), s2.substr(0,n-k))) return mp[s]=true;
            if(helper(s1.substr(0,k), s2.substr(0,k)) && helper(s1.substr(k), s2.substr(k))) return mp[s]=true;
        }
        return mp[s]=false;
    }
    
    bool isScramble(string s1, string s2) {
        return helper(s1, s2);
    }
};