class Solution {
public:
    unordered_map<char, unordered_map<char, char>> mp;
    bool checkSub(string &s, string &sub, int i, int j){
        int k=0;
        for(int a=i; a<=j; ++a){
            if (sub[k] == s[a] || mp[sub[k]][s[a]]) {
                k++;
            } else {
                return false;
            }
        }
        
        return true;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.size();
        int m=sub.size();
        
        for(auto it:mappings){
            mp[it[0]][it[1]] = 1;
        }
        
        if(n<m) return false;
        int i=0, j=0;
        while(j<n){
            if(j-i+1 == m) {
                if(checkSub(s, sub, i, j)) return true;
                else i++;
            }
            
            j++;
        }
        
        return false;
    }
};