class Solution {
public:
    int robHouse(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=n; ++i){
            dp[i]=max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);
        return max(robHouse(nums1), robHouse(nums2));
    }
};