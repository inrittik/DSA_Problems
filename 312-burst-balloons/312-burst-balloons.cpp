class Solution {
public:
    int calcCoins(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int mx = INT_MIN;
        
        for(int k=i; k<=j; ++k){
            int coins = calcCoins(nums, i, k-1, dp) + calcCoins(nums, k+1, j, dp) + nums[i-1]*nums[k]*nums[j+1];
            
            mx = max(mx, coins);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return calcCoins(nums, 1, n, dp);
    }
};