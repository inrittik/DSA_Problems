class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int n){
        if(n<0) return 0;
        else if(n==0) return nums[0];
        else if(n==1) return max(nums[0], nums[1]);
        if(dp[n]!=-1) return dp[n];
        return dp[n]=max(helper(nums, n-1), nums[n]+max(helper(nums, n-2), helper(nums, n-3)));
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return helper(nums, nums.size()-1);
    }
};