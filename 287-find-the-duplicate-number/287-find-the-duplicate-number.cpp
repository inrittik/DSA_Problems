class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1;
        int hi = nums.size()-1;
        int mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            int cnt = 0;
            for(int i:nums){
                if(i<=mid) cnt++;
            }
            if(cnt<=mid) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};