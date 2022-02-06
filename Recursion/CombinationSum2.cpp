// Leetcode - Combination Sum II

class Solution {
public:
    void getCombinations(int ind, vector<int> &osf, vector<vector<int>> &comb,vector<int> candidates, int target){
        if(target==0){
            comb.push_back(osf);
            return;
        }
        else{
            for(int i=ind; i<candidates.size(); ++i){
                if(i>ind && candidates[i]==candidates[i-1]){
                    continue;
                }
                if(target<candidates[i]) break;
                osf.push_back(candidates[i]);
                getCombinations(i+1, osf, comb, candidates, target-candidates[i]);
                osf.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> comb;
        vector<int> osf;
        sort(candidates.begin(), candidates.end());
        getCombinations(0, osf, comb, candidates, target);
        return comb;
    }
};