class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
        int minInd=min_element(nums.begin(), nums.end())-nums.begin(), maxInd=max_element(nums.begin(), nums.end())-nums.begin();
        int diff1=max(maxInd, minInd)+1;
        int diff2=n-min(maxInd, minInd);
        int diff3=(n-abs(maxInd-minInd))+1;
        return min({diff1, diff2, diff3});
    }
};