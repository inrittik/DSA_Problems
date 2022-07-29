class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit = 0;
        int buy = prices[0];
        for(int p:prices){
            if(p<buy){
                buy = p;
            }
            mxProfit = max(mxProfit, p-buy);
        }
        return mxProfit;
    }
};