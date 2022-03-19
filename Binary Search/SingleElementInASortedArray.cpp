// leetcode - 540

// binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        if(n==1) return nums[0];
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(nums[mid]==nums[mid+1]){
                if(mid<n-1 && (mid-lo)%2==0){
                    lo = mid+2;
                }
                else{
                    hi = mid-1;
                }
            }
            else if(mid>0 && nums[mid]==nums[mid-1]){
                if((mid-lo)%2==0){
                    hi = mid-2;
                }
                else{
                    lo = mid+1;
                }
            }
            else return nums[mid];
        }
        return -1;
    }
};


// binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid, ans;
        if(n==1) return nums[0];
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(mid%2==1) mid--;
            
            if(mid<n-1 && nums[mid]==nums[mid+1]){
                lo = mid + 2;
            }
            else{
                hi = mid - 1;
                ans = nums[mid];
            }
        }
        return ans;
    }
};