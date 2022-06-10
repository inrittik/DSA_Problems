typedef pair<int, pair<int, int>> ppi;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<ppi> pq;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(pq.size()>=k && nums1[i]+nums2[j]>pq.top().first) break;
                pq.push({nums1[i]+nums2[j], {nums1[i], nums2[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};