class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        int preSum=0;
        mp[0]=1;
        for(int i=0; i<n; ++i) {
            preSum = (preSum+nums[i])%k;
            if(preSum<0) preSum+=k;
            if(mp.find(preSum) != mp.end()){
                cnt += mp[preSum];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};