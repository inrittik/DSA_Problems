class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size(), ans = INT_MAX;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int M = nums.size();
        for(int i=0;i<M;i++){
            int start = nums[i];
            int last = start+N-1;
            auto it=upper_bound(nums.begin(),nums.end(),last);
            int len = it- nums.begin();
            ans = min(ans,N-(len-i)); 
        }

        return ans;
    }
};