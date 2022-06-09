class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        int i1=nums.size()-2;
        while(i1>=0 && nums[i1]>=nums[i1+1]) i1--;
        if(i1>=0){
            int i2 = nums.size()-1;
            while(nums[i2]<=nums[i1]) i2--;
            swap(nums[i1], nums[i2]);
        }
        reverse(nums.begin()+i1+1, nums.end());
    }
};