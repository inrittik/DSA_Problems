class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& arr, int k, int i){
        int n = arr.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MIN, maxele = arr[i];
        for (int j = i; j < n && j < i + k; j++)
        {
            maxele = max(arr[j], maxele);
            int currans = maxele *(j - i + 1) + helper(arr, k, j+1);
            ans = max(ans, currans);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return helper(arr, k, 0);
    }
};