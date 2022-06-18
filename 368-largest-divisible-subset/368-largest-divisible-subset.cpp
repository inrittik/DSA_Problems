class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int lastInd = 0, maxi = 1;
        for(int i=0; i<n; ++i){
            hash[i];
            for(int j=0; j<i; ++j){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd = i;
            }
        }
        vector<int> v(maxi);
        v[0]=(nums[lastInd]);
        int ind = 1;
        while(hash[lastInd]!=lastInd){
            if(ind>=maxi) break;
            lastInd = hash[lastInd];
            v[ind++]=nums[lastInd];
        }
        return v;
    }
};