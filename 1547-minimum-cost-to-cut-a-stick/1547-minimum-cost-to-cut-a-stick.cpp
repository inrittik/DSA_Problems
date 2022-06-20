class Solution {
public:
    int calcCost(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = INT_MAX;
        for(int k = i; k<=j; ++k){
            int cost = calcCost(cuts, i, k-1, dp) + calcCost(cuts, k+1, j, dp) + cuts[j+1] - cuts[i-1];
            mn = min(cost, mn);
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return calcCost(cuts, 1, c, dp);
    }
};