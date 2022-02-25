// Leetcode - Minimum Cost Climbing Stairs

class Solution {
public:
    vector<int> dp;
    int minCost(vector<int>& cost, int n){
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2; i<=n; ++i){
            dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size()+1, -1);
        return min(minCost(cost, cost.size()-1), minCost(cost, cost.size()-2));
    }
};