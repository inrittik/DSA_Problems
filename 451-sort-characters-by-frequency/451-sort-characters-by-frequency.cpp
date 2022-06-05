class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; ++i) mp[s[i]]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        
        string ans="";
        while(pq.size()>0){
            char c = pq.top().second;
            int f = pq.top().first;
            while(f>0){
                ans.push_back(c);
                f--;
            }
            
            pq.pop();
        }
        
        return ans;
    }
};