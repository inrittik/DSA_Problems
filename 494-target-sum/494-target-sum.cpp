class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        int zeroes = 0;
        for(int i=0; i<n; ++i) {
            sum+=nums[i];
            if(nums[i]==0) zeroes++;
        }
        
        int new_target = (sum+target)/2;
        if((sum+target)%2!=0 || sum<target || target<-sum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(new_target+1));
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=new_target; ++j){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        }

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=new_target; ++j){
                if(nums[i-1]<=j && nums[i-1]!=0){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][new_target]*pow(2, zeroes);
    }
};