class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dist=0;
        int i=0;
        while(i<n && i<=dist){
            dist=max(dist, i+nums[i]);
            i++;
        }
        if(dist>=n-1) return true;
        else return false;
    }
};