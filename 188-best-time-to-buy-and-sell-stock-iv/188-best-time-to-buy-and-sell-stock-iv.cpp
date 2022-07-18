class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int n, int traNum, int k){
        if(n==prices.size() || traNum==2*k) return 0;
        
        if(dp[n][traNum]!=-1) return dp[n][traNum];
        
        if(traNum%2==0){
            int buy = -prices[n]+helper(prices, n+1, traNum+1, k);
            int notBuy = helper(prices, n+1, traNum, k);
            
            return dp[n][traNum]=max(buy, notBuy);
        }
        else{
            int sell = prices[n]+helper(prices, n+1, traNum+1, k);
            int notSell = helper(prices, n+1, traNum, k);
            
            return dp[n][traNum]=max(sell, notSell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(2*k, -1));
        return helper(prices, 0, 0, k);
    }
};