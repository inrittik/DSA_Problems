class Solution {
public:
    vector<vector<long long>> dp;
    long long findSum(vector<int>& nums, int n, int picked){
        if(n<0) return 0;
        if(dp[n][picked]!=-1) return dp[n][picked];
        long long taken = findSum(nums, n-1, !picked);
        long long notTaken = findSum(nums, n-1, picked);
        if(!picked){
            return dp[n][picked]=max(notTaken, nums[n]+taken);
        }
        else{
            return dp[n][picked]=max(notTaken, taken-nums[n]);
        }
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size(), vector<long long>(2, -1));
        return findSum(nums, nums.size()-1, 0);
    }
};