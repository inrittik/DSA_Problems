class Solution {
public:
    vector<string> ans;
    void helper(string& s, string osf, set<string>& st, int i){
        if(i==s.size()){
            ans.push_back(osf);
            return;
        }
        if(osf.size()>0) osf+=" ";
        string temp = "";
        for(int k=i; k<s.size(); ++k){
            temp.push_back(s[k]);
            if(st.find(temp)!=st.end()){
                helper(s, osf+temp, st, k+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        helper(s, "", st, 0);
        return ans;
    }
};