class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i:arr) mp[i]++;
        
        priority_queue<int> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int sz = n;
        int cnt = 0;
        while(!pq.empty() && sz>n/2){
            sz -= pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};