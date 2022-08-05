class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int pre = 1, suff = 1;
        
        vector<int> ans(n, 1);
        for(int i=0; i<n; ++i){
            ans[i] *= pre;
            pre *= nums[i];
            
            ans[n-1-i] *= suff;
            suff *= nums[n-1-i];
        }
        
        return ans;
    }
};