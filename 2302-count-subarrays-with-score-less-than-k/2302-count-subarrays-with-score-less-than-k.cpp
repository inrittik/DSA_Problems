class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long preSum = 0;
        int i=0, j=0;
        long long cnt = 0;
        while(j<n){
            preSum+=nums[j];
            long long score = preSum*(j-i+1);
            while(score>=k){
                preSum-=nums[i++];
                score = preSum*(j-i+1);
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};