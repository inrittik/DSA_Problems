class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int range = 0;
        for(int i=0; i<n; ++i) range+=nums[i];
        if(range%2!=0) return false;
        range/=2;
        vector<vector<bool>> dp(n+1, vector<bool>(range+1));
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=range; ++j){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        }

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=range; ++j){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][range];
    }
};