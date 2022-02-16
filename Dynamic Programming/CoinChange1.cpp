// leetcode - coin change 1

class Solution {
public:
    int min(int a, int b){
        if(a<b) return a;
        else return b;
    }
    int coinChange(vector<int>& arr, int sum) {
        int n = arr.size();
        long long dp[n+1][sum+1];
        for(int i=0;i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(i==0) dp[i][j]=INT_MAX-1;
                if(j==0) dp[i][j]=0;
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j], dp[i][j-arr[i-1]]+1);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][sum]==INT_MAX-1) return -1;
        return dp[n][sum];
    }
};