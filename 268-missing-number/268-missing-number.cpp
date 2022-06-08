class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1, -1);
        for(int i=0; i<n; ++i) v[nums[i]]=i;
        
        for(int i=0; i<=n; ++i){
            if(v[i]==-1) return i;
        }
        return -1;
    }
};