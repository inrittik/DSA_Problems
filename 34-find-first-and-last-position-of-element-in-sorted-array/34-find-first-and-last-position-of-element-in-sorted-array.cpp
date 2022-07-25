class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1, -1};
        int lo = 0, hi = n-1, mid;
        int a, b;
        while(hi-lo>1){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        if(nums[lo]==target){
            a = lo;
        }
        else if(nums[hi]==target){
            a = hi;
        }
        else{
            return {-1, -1};
        }
        
        lo = a, hi = n-1;
        while(hi-lo>1){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<=target){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        if(nums[lo]>target){
            b = lo-1;
        }
        else if(nums[hi]>target){
            b = hi-1;
        }
        else if(nums[n-1]==target){
            b= n-1;
        }
        
        return {a, b};
    }
};