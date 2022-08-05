class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre(n), suff(n);
        
        int prod = 1;
        for(int i=0; i<n; ++i) {
            prod*=nums[i];
            pre[i] = prod;
        }
        prod = 1;
        for(int i=n-1; i>=0; --i){
            prod*=nums[i];
            suff[i] = prod;
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
            if(i==0) ans[i] = suff[i+1];
            else if(i==n-1) ans[i] = pre[i-1];
            else{
                ans[i] = pre[i-1]*suff[i+1];
            }
        }
        
        return ans;
    }
};