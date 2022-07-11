class Solution {
public:
    int helper(vector<int>& prices, int day, bool buy, vector<vector<int>> &memo){ 
        if(day >= prices.size()){
            return 0;
        }
        int &ans = memo[day][buy];
        
        if(ans != -1){
            return ans;
        }
        int ans1 = helper(prices, day + 1, buy, memo);
 
        int ans2 = 0;

        if(buy){
            ans2 = -prices[day] + helper(prices, day + 1, false, memo);
        }else{
            ans2 = prices[day] + helper(prices, day + 2, true, memo);
        }
        
        return ans = max(ans1, ans2);
        
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0; 
        vector<vector<int>> memo(prices.size() + 2, vector<int>(2, -1));
        ans = helper(prices, 0, true, memo);
        return ans;
    }
};