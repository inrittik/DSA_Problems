class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int len = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int k = 0;
                if(dp[i][j]==-1){
                    while(i+k<n && j+k<m && nums1[i+k]==nums2[j+k]){
                        k++;
                    }
                    while(k) dp[i+k][j+k] = k--;
                }
                len = max(len, dp[i][j]);
            }
        }
        return len;
    }
};