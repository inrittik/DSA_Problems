class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dist=0;
        int i=0;
        while(i<n){
            dist=max(i+nums[i], dist);
            if(dist>=n-1) return true;
            else if(dist<=i) return false;
            i++;
        }
        return false;
    }
};