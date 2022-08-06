class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins, int amount, int n){
        if(n>=coins.size()) return INT_MAX-1;
        if(amount==0) return 0;
        
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int pick, notPick;
        if(coins[n]<=amount){
            pick = helper(coins, amount-coins[n], n);
            notPick = helper(coins, amount, n+1);
            
            return dp[n][amount]=min(1+pick, notPick);
        }
        else{
            notPick = helper(coins, amount, n+1);
            return dp[n][amount]=notPick;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        dp.resize(n, vector<int>(amount+1, -1));
        
        int ans = helper(coins, amount, 0);
        
        return ans==INT_MAX-1?-1:ans;
    }
};