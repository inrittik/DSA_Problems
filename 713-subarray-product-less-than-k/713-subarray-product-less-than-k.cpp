class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1;
        int n=nums.size();
        int i=0, j=0;
        int cnt=0;
        while(j<n){
            prod*=nums[j];
            while(prod>=k && i<=j){
                prod/=nums[i++];
            }
            if(prod<k) cnt+= j-i+1;
            j++;
        }
        return cnt;
    }
};