class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=2; i<n; ++i){
            int start = 0, end = i-1;
            while(start<end){
                if(nums[start]+nums[end]>nums[i]){
                    ans += (end-start);
                    end--;
                }
                else start++;
            }
        }
        return ans;
    }
};