// Leetcode - Subsets II

class Solution {
public:
    void getSubsets(set<vector<int>> &s, vector<int> osf, int ind, int n, vector<int> nums){
        if(ind==n){
            s.insert(osf);
        }
        else{
            getSubsets(s, osf, ind+1, n, nums);
            osf.push_back(nums[ind]);
            getSubsets(s, osf, ind+1, n, nums);
        }
    }    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> osf;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        getSubsets(s, osf, 0, nums.size(), nums);
        // for(int i=0; i<subset.size(); ++i) s.insert(subset[i]);
        // subset.clear();
        for(auto it:s){
            subset.push_back(it);
        }
        return subset;
    }
};