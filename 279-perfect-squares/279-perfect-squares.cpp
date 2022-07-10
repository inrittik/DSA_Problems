class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int cnt = n;
        for(int i=sqrt(n); i>=1; --i){
            cnt=min(cnt,1+helper(n-i*i));
        }
        return dp[n]=cnt;
    }
    int numSquares(int n) {
        dp.resize(n+1, -1);
        return helper(n);
    }
};