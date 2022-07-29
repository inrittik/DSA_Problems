class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mxSum = nums[0];
        for(int n:nums){
            sum += n;
            mxSum = max(mxSum, sum);
            sum = max(0, sum);
        }
        
        return mxSum;
    }
};