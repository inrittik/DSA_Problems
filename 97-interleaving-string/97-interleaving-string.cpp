class Solution {
public:
    unordered_map<string,int> dp;
    bool helper(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        string key = to_string(p1)+'*'+to_string(p2)+'*'+to_string(p3);
        if(p3==s3.size()) return true;
        if(dp.count(key)) return dp[key];
        if(s1[p1]==s3[p3] && p1<s1.size() && helper(s1, s2, s3, p1+1, p2, p3+1)) return dp[key]=true;
        if(s2[p2]==s3[p3] && p2<s2.size() && helper(s1, s2, s3, p1, p2+1, p3+1)) return dp[key]=true;
        
        return dp[key]=false;
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

        return helper(s1, s2, s3, 0, 0, 0);
    }
};