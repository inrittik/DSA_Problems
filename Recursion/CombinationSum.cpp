// Leetcode - Combinations Sum

class Solution {
public:
    void findCombinations(int ind, int target, vector<int> &candidates,vector<int> &ds, vector<vector<int>> &ans){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombinations(ind, target-candidates[ind], candidates, ds, ans);
            ds.pop_back();
        }
        findCombinations(ind+1, target, candidates, ds, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ds, ans);
        return ans;
    }
};