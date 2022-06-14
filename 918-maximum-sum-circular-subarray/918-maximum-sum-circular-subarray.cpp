class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        int mx = nums[0];
        int currmx = 0, currmn = 0;
        int sum = 0;
        for(int i=0; i<n; ++i){
            currmx = max(currmx+nums[i], nums[i]);
            currmn = min(currmn+nums[i], nums[i]);
            
            mx = max(mx, currmx);
            mn = min(mn, currmn);
            
            sum+=nums[i];
        }
        
        if(mx>0) return max(mx, sum - mn);
        else return mx;
    }
};