class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int n, int traNum){
        if(n==prices.size() || traNum==4) return 0;
        
        if(dp[n][traNum]!=-1) return dp[n][traNum];
        
        // only buy
        if(traNum%2==0){
            int buy = -prices[n]+helper(prices, n+1, traNum+1);
            int notBuy = helper(prices, n+1, traNum);
            
            return dp[n][traNum]=max(buy, notBuy);
        }
        else{
            int sell = prices[n]+helper(prices, n+1, traNum+1);
            int notSell = helper(prices, n+1, traNum);
            
            return dp[n][traNum]=max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(4, -1));
        return helper(prices, 0, 0);
    }
};