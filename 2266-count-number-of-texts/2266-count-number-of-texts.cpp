class Solution {
public:
    vector<int> dp;
    int mod = 1e9 + 7;
    static constexpr int keys[10] = {0,0,3,3,3,3,3,4,3,4};
    int helper(string& s, int i){
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int digit = s[i]-'0'; long counts = 0;
        for(int k = 0; k < keys[digit] && i+k < s.length() && s[i] == s[i+k]; k++) {
            counts += helper(s, i+k+1);
            counts %= mod;
        }
        return dp[i] = counts%mod;
    }
    
    int countTexts(string pressedKeys) {
        dp.resize(pressedKeys.size(), -1);
        return helper(pressedKeys, 0);
    }
};