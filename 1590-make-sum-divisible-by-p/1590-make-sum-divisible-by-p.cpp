class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int rem=0;
        for(int i:nums) rem=(rem+i)%p;
        if(rem==0) return 0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        int sum=0;
        int ans=n;
        for(int i=0; i<n; ++i){
            sum = (sum+nums[i])%p;
            int val = (sum-rem+p)%p;
            if(mp.find(val)!=mp.end()){
                ans=min(ans, i-mp[val]);
            }
            mp[sum]=i;
        }
        return ans==n?-1:ans;
    }
};