class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        
        int prev = nums[1] - nums[0];
        if(n==2) {
            if(prev!=0) return 2;
        }
        if(*max_element(nums.begin(), nums.end())==*min_element(nums.begin(), nums.end())) return 1;
        
        int cnt = 2;
        for(int i=2; i<n; ++i){
            if(prev>0 && nums[i]-nums[i-1]<0){
                prev = nums[i]-nums[i-1];
                cnt++;
            }
            else if(prev<0 && nums[i]-nums[i-1]>0){
                prev = nums[i]-nums[i-1];
                cnt++;
            }
            else if(prev==0) prev = nums[i]-nums[i-1];
        }
        
        return cnt;
    }
};