class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();
        int sum = 0;
        vector<int> ans(m);
        for(int i:nums) if(i%2==0) sum+=i;
        for(int i=0; i<m; ++i){
            int prev = nums[queries[i][1]];
            int num = prev+queries[i][0];
            nums[queries[i][1]] = num;
            if(num%2==0){
                if(prev%2==0){
                    sum+=(num-prev);
                }
                else sum+=num;
            }
            else{
                if(prev%2==0){
                    sum-=prev;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};