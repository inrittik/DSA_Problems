// leetcode - 34

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1, -1};
        int lo = 0, hi = n-1, mid;
        int a, b;
        
        // loop for first pos -> lower bound implementation with one change -> element at pos should be equal to target
        while(hi-lo>1){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        if(nums[lo]==target){ // pos 'lo' element is the target
            a = lo;
        }
        else if(nums[hi]==target){ // pos 'hi' element is the target
            a = hi;
        }
        else{
            return {-1, -1}; // element is not present in array
        }
        
        // loop for last pos -> upper bound implementation with changes -> if pos 'lo' element is greater than target, b = lo - 1, similarly we check for pos 'hi'. If last element if equal to target than it is the last pos
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
        if(nums[lo]>target){ // element at pos 'lo-1' is b
            b = lo-1;
        }
        else if(nums[hi]>target){ // element at pos 'hi-1' is b
            b = hi-1;
        }
        else if(nums[n-1]==target){ // last element is equal to target
            b = n-1;
        }
        
        return {a, b};
    }
};