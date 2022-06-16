class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int ind, int prev_ind){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]) return dp[ind][prev_ind+1]=max(helper(nums, ind+1, prev_ind), helper(nums, ind+1, ind)+1);
        else return dp[ind][prev_ind+1]=helper(nums, ind+1, prev_ind);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1, vector<int>(nums.size()+1, -1));
        return helper(nums, 0, -1);
    }
};