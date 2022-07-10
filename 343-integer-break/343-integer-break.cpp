class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int mxProd = 1;
        for(int i=1;i<n; ++i){
            mxProd = max(mxProd, helper(n-i)*i);
        }
        return dp[n]=max(mxProd, n);
    }
    int integerBreak(int n) {
        if(n==2) return 1;
        dp.resize(n+1, -1);
        int mxProd = 1;
        for(int i=1; i<n; ++i){
            mxProd = max(mxProd, helper(n-i)*i);
        }
        return mxProd;
    }
};