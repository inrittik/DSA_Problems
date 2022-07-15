class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& days, vector<int>& costs, int n, vector<bool>& map){
        if(n>365) return 0;
        if(dp[n]!=-1) return dp[n];
        if(!map[n]) return dp[n] = helper(days, costs, n+1, map);
        
        return dp[n] = min({costs[0]+helper(days, costs, n+1, map), costs[1]+helper(days, costs, n+7, map), costs[2]+helper(days, costs, n+30, map)});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(366, -1);
        vector <bool> map(366, false);
        for(auto x: days) map[x] = true;  
        return helper(days, costs, 0, map);
    }
};