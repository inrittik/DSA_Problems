class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> fre(10001);
        for(int n:barcodes) fre[n]++;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<10001; ++i){
            if(fre[i]==0) continue;
            pq.push({fre[i],i});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            ans.push_back(t.second);
            t.first--;
            if(!pq.empty()){
                auto s = pq.top();
                pq.pop();
                ans.push_back(s.second);
                s.first--;
                if(s.first>0) pq.push(s);
            }
            if(t.first>0) pq.push(t);
        }
        return ans;
    }
};