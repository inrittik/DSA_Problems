class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int k){
        if(k==0 || k==1) return k;
        if(n==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int temp, mn=INT_MAX;
        for(int f=1; f<=k; ++f){
            temp=max(solve(n-1, f-1), solve(n, k-f))+1;
            mn=min(temp, mn);
        }
        return dp[n][k]=mn;
    }
    int twoEggDrop(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(2,n);
    }
};