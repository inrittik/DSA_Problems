class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
        int minInd=0, maxInd=0;
        int mx=nums[0], mn = nums[0];
        for(int i=1; i<n; ++i){
            if(nums[i]>mx){
                mx=nums[i];
                maxInd=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                minInd=i;
            }
        }
        int diff1=max(maxInd, minInd)+1;
        int diff2=n-min(maxInd, minInd);
        int diff3=(n-abs(maxInd-minInd))+1;
        return min(diff1, min(diff2, diff3));
    }
};