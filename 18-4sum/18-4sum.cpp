class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(long(nums[i])+long(nums[i+1])+long(nums[i+2])+long(nums[i+3])>target) break;
            if(long(nums[i])+long(nums[n-1])+long(nums[n-2])+long(nums[n-3])<target) continue;
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; ++j){
                if(long(nums[i])+long(nums[j])+long(nums[j+1])+long(nums[j+2])>target)break; 
                if(long(nums[i])+long(nums[j])+long(nums[n-1])+long(nums[n-2])<target)continue;
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int lo=j+1, hi=n-1;
                while(lo<hi){
                    long sum=nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(sum==target) {
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo++;hi--;
                    }
                    else if(sum<target) lo++;
                    else hi--;
                }
            }
        }
        
        return ans;
    }
};