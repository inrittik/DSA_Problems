class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> path(10);
        path[0]={4,6}, path[1]={6,8}, path[2]={7,9}, path[3]={4,8}, path[4]={0,3,9}, path[5]={}, path[6]={0,1,7}, path[7]={2,6}, path[8]={1,3}, path[9]={2,4};
        
        vector<vector<long long>> dp(n+1, vector<long long>(10,0));
        for(int j=0; j<10; ++j) {
            dp[0][j]=0;
            dp[1][j]=1;
        }
        int mod=1e9+7;
        for(int i=2; i<=n; ++i){
            for(int j=0; j<10; ++j){
                for(int a:path[j]){
                    dp[i][j]=dp[i][j]+dp[i-1][a];
                }
                dp[i][j]%=mod;
            }
        }
        
        long long sum = 0;
        for(int i=0; i<10; ++i){
            sum=sum+dp[n][i]%mod;
        }
        return sum%mod;
    }
};