class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c+2, vector<int>(c+2));
        
        for(int i=c; i>=1; --i){
            for(int j=1; j<=c; ++j){
                if(i>j) continue;
                int mn = INT_MAX;
                for(int k = i; k<=j; ++k){
                    int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                    mn = min(cost, mn);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][c];
    }
};