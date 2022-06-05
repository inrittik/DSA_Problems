typedef pair<int, int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=*max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int s=nums.size();
        for(int i=0; i<s; ++i){
            mp[nums[i]]++;
        }
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};