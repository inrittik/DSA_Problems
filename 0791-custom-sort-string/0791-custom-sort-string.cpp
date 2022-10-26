class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> f(26);
        for(int i=0; i<s.size(); ++i) f[s[i]-'a']++;
        string res = "";
        for(int i=0; i<order.size(); ++i){
            while(f[order[i]-'a']){
                res+=(order[i]);
                f[order[i]-'a']--;
            }
        }
        for(int i=0; i<26; ++i){
            while(f[i]){
                res+=(i+'a');
                f[i]--;
            }
        }
        return res;
    }
};