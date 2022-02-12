// Coding ninja - Partition with given difference

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int range=0;
    for(int i=0; i<n; ++i) range+=arr[i];
    int sum = range-d;
    if(sum<=0) return 0;
    if(sum%2==1) return 0;
    else{
        sum/=2;
        long long max=1e9+7;
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
                    dp[i][j]=(dp[i-1][j]%max+dp[i-1][j-arr[i-1]]%max)%max;
                }
                else{
                    dp[i][j]=dp[i-1][j]%max;
                }
            }
        }
        return dp[n][sum]%max;
    }
}


