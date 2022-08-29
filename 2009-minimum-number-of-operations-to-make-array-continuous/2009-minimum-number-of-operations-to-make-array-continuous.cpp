class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), i = 0, j = 0, ans = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int M = nums.size(); j < M; ++j) {
            while (nums[i] + N <= nums[j]) ++i;
            ans = max(ans, j - i + 1);
        }
        return N-ans;
    }
};