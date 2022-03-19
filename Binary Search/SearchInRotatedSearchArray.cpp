// leetcode - 33

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(nums[mid]>nums[hi]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        int rot = lo;
        int realmid;
        lo = 0, hi = n-1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            realmid = (mid+rot)%n;
            if(nums[realmid]==target) return realmid;
            else if(nums[realmid]<target){
                lo=mid+1;
            }
            else hi = mid-1;
        }
        return -1;
    }
};