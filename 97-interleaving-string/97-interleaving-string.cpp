class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool helper(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        if(p3==s3.size()) return true;
        if(dp[p1][p2][p3]!=-1) return dp[p1][p2][p3];
        if(s1[p1]==s3[p3] && p1<s1.size() && helper(s1, s2, s3, p1+1, p2, p3+1)) return dp[p1][p2][p3]=true;
        if(s2[p2]==s3[p3] && p2<s2.size() && helper(s1, s2, s3, p1, p2+1, p3+1)) return dp[p1][p2][p3]=true;
        
        return dp[p1][p2][p3]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        
        vector<int> v(26);
        for(char c:s1){
            v[c-'a']++;
        }
        for(char c:s2){
            v[c-'a']++;
        }
        for(char c:s3){
            v[c-'a']--;
        }
        if(*max_element(v.begin(), v.end())!=0) return false;
        
        dp.resize(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};