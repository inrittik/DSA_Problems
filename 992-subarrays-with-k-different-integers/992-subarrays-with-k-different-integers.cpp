class Solution {
public:
    unordered_map<int, int> mp;
    int checkSub(vector<int>& nums, int i, int j, int k){
        int t=i;
        int cnt = 0;
        while(mp.size()==k && i<=j){
            mp[nums[i]]--;
            if(mp[nums[i]]==0) {
                cnt=i-t+1;
                break;
            }
            i++;
        }
        while(i>=t) mp[nums[i--]]++;
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        int cnt = 0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size()==k){
                cnt= cnt+checkSub(nums, i, j, k);
            }
            j++;
        }
        
        return cnt;
    }
};