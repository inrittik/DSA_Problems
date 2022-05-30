class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0; i<n; ++i) sum+=nums[i];
        
        int mn=*min_element(nums.begin(), nums.end());
        
        return sum-(long long)(mn*n);
    }
};