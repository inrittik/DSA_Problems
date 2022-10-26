class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prevVal=0, sum=0;
        for(int i:nums){
            sum+=i;
            int val=sum%k;
            if(mp.count(val)) return true;
            mp[prevVal]++;
            prevVal=val;
        }
        return false;
    }
};