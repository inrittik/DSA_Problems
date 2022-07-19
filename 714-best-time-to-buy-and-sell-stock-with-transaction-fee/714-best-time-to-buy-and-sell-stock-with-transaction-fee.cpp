class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int n, int status, int& fee){
        if(n==prices.size()) return 0;
        
        if(dp[n][status]!=-1) return dp[n][status];
        
        if(!status){
            int buy = -prices[n]+helper(prices, n+1, !status, fee);
            int notBuy = helper(prices, n+1, status, fee);
            
            return dp[n][status]=max(buy, notBuy);
        }
        else{
            int sell = prices[n]-fee+helper(prices, n+1, !status, fee);
            int notSell = helper(prices, n+1, status, fee);
            
            return dp[n][status]=max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return helper(prices, 0, 0, fee);
    }
};