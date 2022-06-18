class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), cur(n+1);
        for(int ind = n-1; ind>=0; --ind){
            for(int prev_ind = ind-1; prev_ind>=-1; --prev_ind){
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]) cur[prev_ind+1]=max(next[prev_ind+1], next[ind+1]+1);
                else cur[prev_ind+1]=next[prev_ind+1];
            }
            next = cur;
        }
        return cur[0];
    }
};