class Solution {
public:
    int change(int sum, vector<int>& arr) {
        int n = arr.size();
        long long dp[n+1][sum+1];
        for(int i=0;i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(i==0) dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+ dp[i][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};