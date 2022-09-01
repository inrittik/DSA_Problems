class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        string res = "";
        stack<pair<int,char>> st;
        auto top = pq.top();
        pq.pop();
        res.push_back(top.second);
        top.first--;
        if(top.first>0) pq.push(top);int k = 0;
        while(!pq.empty()){
            char c = pq.top().second;
            while(!pq.empty() && c==res[k]){
                st.push(pq.top());
                pq.pop();
                if(pq.empty()) return "";
                c = pq.top().second;
            }
            res.push_back(c);
            auto top = pq.top();
            pq.pop();
            top.first--;
            if(top.first>0) pq.push(top);
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
            k++;
        }
        return res;
    }
};