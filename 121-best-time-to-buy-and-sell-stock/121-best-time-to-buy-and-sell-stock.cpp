class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int buy=INT_MAX;
        int profit=INT_MIN;
        for(int i=0; i<n; ++i){
            if(buy>prices[i]){
                buy=prices[i];
            }
            profit=max(profit, prices[i]-buy);
        }
        
        return profit;
    }
};