class Solution {
public:
    vector<vector<int>> dp;
    int helper(string& s, string& t, int i, int j){
        if(i==0) return j;
        else if(j==0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==t[j-1]) return dp[i][j]=helper(s, t, i-1,j-1);
        else{
            return dp[i][j]=1+min(min(helper(s, t, i-1, j-1), helper(s, t, i, j-1)), helper(s, t, i-1, j));
        }
    }
    int minDistance(string s, string t) {
        dp.resize(s.size()+1, vector<int>(t.size()+1, -1));
        return helper(s, t, s.size(), t.size());
    }
};