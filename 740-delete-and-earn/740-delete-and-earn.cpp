class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int>count(n+1,0);  
        for(int i=0; i<nums.size(); i++){
           count[nums[i]]++; 
        }

        int dp[n+1];
        dp[0]=count[0];
        dp[1]=max(count[1],count[0]);
        for(int i=2; i<n+1; i++){
            dp[i]=max(count[i]*i+dp[i-2], dp[i-1]); 
        }
        return max(dp[n-1],dp[n]);
    }
};