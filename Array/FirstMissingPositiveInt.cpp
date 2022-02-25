// Leetcode - First Missing positive integer 41

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            i++;
        }
        i=0;
        while(i<n){
            if(nums[i]!=i+1){
                break;
            }
            i++;
        }
        return i+1;
    }
};