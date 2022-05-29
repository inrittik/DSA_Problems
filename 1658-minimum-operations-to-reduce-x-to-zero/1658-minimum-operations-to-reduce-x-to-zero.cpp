class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int i:nums) total+=i;
        int target=total-x;
        int i=0, j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && sum>target){
                sum-=nums[i++];
            }
            if(sum==target){
                ans=max(ans, j-i+1);
            }
            j++;
        }
        return ans == 0 ? (target == 0 ? n : -1) : n - ans;
    }
};