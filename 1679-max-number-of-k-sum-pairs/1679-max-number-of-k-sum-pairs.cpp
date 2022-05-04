class Solution {
public:
    int numOfOperations(vector<int>&nums, int l, int h, int k){
        if(l>=h) return 0;
        while(l<h){
            if(nums[l]+nums[h]==k){
                return 1+numOfOperations(nums, l+1, h-1, k);
            }
            else if(nums[l]+nums[h]<k){
                l++;
            }
            else{
                h--;
            }
        }
        
        return 0;
    }
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        return numOfOperations(nums, 0, nums.size()-1, k);
    }
};