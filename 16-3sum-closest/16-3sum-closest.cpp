class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mnSum = abs(target-(nums[n-1]+nums[n-2]+nums[n-3]));
        int sign = 1;
        if((nums[n-1]+nums[n-2]+nums[n-3])<target) sign=-1;
        for(int i=0; i<n; ++i){
            int sum = nums[i];
            int lo = 0, hi = n-1;
            while(lo<hi){
                if(lo!=i && hi!=i){
                    if(abs(target-(sum+nums[lo]+nums[hi]))<mnSum){
                        mnSum = abs(target-(sum+nums[lo]+nums[hi]));
                        if((sum+nums[lo]+nums[hi])<target){
                            sign = -1;
                        }
                    }
                    if(sum+nums[lo]+nums[hi]<target){
                        lo++;
                    }
                    else if(sum+nums[lo]+nums[hi]>target){
                        hi--;
                    }
                    else{
                        mnSum = 0;
                        break;
                    }
                }
                else if(lo==i) lo++;
                else if(hi==i) hi--;
            }
        }
        return target+mnSum*sign;
    }
};