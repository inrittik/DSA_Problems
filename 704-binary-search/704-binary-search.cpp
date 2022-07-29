class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int mid;
        while(hi-lo>1){
            mid = (hi-lo)/2+lo;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        if(nums[lo]==target) return lo;
        if(nums[hi]==target) return hi;
        
        return -1;
    }
};