// leetcode - 162


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        if(n==1) return 0;
        if(n==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            if(mid>0 && mid<n-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
                }
                else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                    lo = mid+1;
                }
                else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                    hi = mid-1;
                }
                else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                    if(nums[mid-1]<nums[mid+1]){
                        lo=mid+1;
                    }
                    else{
                        hi=mid-1;
                    }
                }
            }
            
            else{
                if(mid==0 && nums[mid]<nums[mid+1]){
                    lo = mid+1;
                }
                else if(mid==n-1 && nums[mid]<nums[mid-1]){
                    hi = mid-1;
                }
                else return mid;
            }
        }
        return -1;
    }
};