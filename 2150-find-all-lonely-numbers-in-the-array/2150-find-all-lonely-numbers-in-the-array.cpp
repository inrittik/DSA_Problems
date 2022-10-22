class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        vector<int> ans;
        for(auto it:mp){
            if(it.second>1) continue;
            if(!mp.count(it.first-1) && !mp.count(it.first+1)) ans.push_back(it.first);
        }
        return ans;
    }
};