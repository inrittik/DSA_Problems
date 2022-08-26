class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<n; ++i){
            if(mp[nums[i]]>n/3) continue;
            mp[nums[i]]++;
            if(mp[nums[i]]>n/3){
                ans.push_back(nums[i]);
                if(ans.size()==2) break;
            }
        }
        return ans;
    }
};