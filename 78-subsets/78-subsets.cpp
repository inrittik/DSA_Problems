class Solution {
public:
    set<vector<int>> ss;
    void genSubsets(vector<int>& nums, vector<int>& osf,int i){
        if(i==nums.size()) {
            ss.insert(osf);
            return;
        }
        osf.push_back(nums[i]);
        genSubsets(nums, osf, i+1);
        osf.pop_back();
        genSubsets(nums, osf, i+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> osf;
        vector<vector<int>> ans;
        genSubsets(nums, osf, 0);
        for(auto it:ss){
            ans.push_back(it);
        }
        return ans;
    }
};