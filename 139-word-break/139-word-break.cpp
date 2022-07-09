class Solution {
public:
    unordered_map<int, bool> mp;
    bool helper(string s, set<string>& st, int i){
        if(i==s.size()) return true;
        if(mp.count(i)) return mp[i];
        for(int k=i; k<s.size(); ++k){
            string temp = s.substr(i, k-i+1);
            if(st.find(temp)!=st.end()) if(helper(s, st, k+1)) return mp[i]=true;
        }
        
        return mp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        return helper(s, st, 0);
    }
};