class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int prevVal=0, sum=0;
        for(int i=0; i<n; ++i){
            sum+=nums[i];
            int val=sum%k;
            if(mp.find(val)!=mp.end()){
                return true;
            }
            mp[prevVal]++;
            prevVal=val;
        }
        
        return false;
    }
};