class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        if(n<2) return n;
        for(int i=1; i<n; ++i){
            if(nums[i]!=nums[i-1]){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};