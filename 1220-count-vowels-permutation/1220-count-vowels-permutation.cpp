class Solution {
public:
    int mod = 1e9+7;
    const unordered_map<char, vector<char>> mp{ {'s', {'a', 'e', 'i', 'o', 'u'} }, 
                                                      {'a', {'e'}}, 
                                                      {'e', {'a', 'i'}}, 
                                                      {'i', {'a', 'e', 'o', 'u'}}, 
                                                      {'o', {'i', 'u'}},
                                                      {'u', {'a'}}};
    unordered_map<char, vector<int>> dp;
    int helper(char prev, int n){
        if(n == 0) return 1;
        
        if(dp[prev][n]) return dp[prev][n];
        for(auto c : mp.at(prev))
            dp[prev][n] = (dp[prev][n] + helper(c, n-1)) % mod;  
        return dp[prev][n];
    }
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return helper('s', n);
    }
};