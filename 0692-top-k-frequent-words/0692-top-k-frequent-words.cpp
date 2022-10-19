typedef pair<int, string> pps;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string, int> mp;
        for(int i=0; i<n; ++i) mp[words[i]]++;
        
        auto comp = [&](const pps& a, const pps& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        
        priority_queue<pps, vector<pps>, decltype(comp)> pq(comp);
        for(auto it:mp){
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        
        vector<string> res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};