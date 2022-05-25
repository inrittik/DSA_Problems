class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        vector<int> v(101, 0);
        for(int i=0; i<n; ++i) {
            mp[nums[i]]++;
            v[nums[i]]++;
        }
        for(int i=1; i<=100; ++i){
            v[i]+=v[i-1];
        }
        vector<int> res;
        for(int i=0; i<n; ++i){
            res.push_back(v[nums[i]]-mp[nums[i]]);
        }
        return res;
    }
};