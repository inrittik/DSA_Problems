class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char c:tasks) mp[c]++;      
        vector<int> last(26);
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
        }
        int cnt = 0;
        while(!pq.empty()){
            int k = n+1;
            vector<pair<int,char>> v;
            while(k>0 && !pq.empty()){
                auto top = pq.top();
                pq.pop();
                top.first--;
                v.push_back(top);
                k--;
                cnt++;
            }
            for(auto it:v){
                if(it.first>0) pq.push(it);
            }
            if(pq.empty()) break;
            cnt+=k;
        }
        return cnt;
    }
};