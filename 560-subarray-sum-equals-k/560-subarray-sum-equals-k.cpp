class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        int preSum=0;
        mp[0]=1;
        for(int i=0; i<n; ++i) {
            preSum += nums[i];
            int val = preSum - k;
            if(mp.find(val) != mp.end()){
                cnt += mp[val];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};