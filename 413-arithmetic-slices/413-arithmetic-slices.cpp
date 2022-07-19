class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        
        int ans = 0;
        int diff;
        
        for(int i=0; i<n-2; ++i){
            diff = nums[i+1]-nums[i];
            
            for(int j=i+1; j<n-1; ++j){
                if(nums[j+1]-nums[j]==diff) ans++;
                else{
                    break;
                }
            }
        }
        
        return ans;
    }
    
};