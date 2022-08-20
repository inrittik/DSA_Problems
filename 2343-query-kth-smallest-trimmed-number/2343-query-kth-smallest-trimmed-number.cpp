class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
            priority_queue<pair<string, int>> pq;
            for(int j=0; j<nums.size(); ++j){
                string tmp = nums[j].substr(nums[j].size()-queries[i][1]);
                
                pq.push({tmp, j});
                if(pq.size()>queries[i][0]){
                    pq.pop();
                }
            }
            ans[i] = pq.top().second;
        }
        return ans;
    }
};