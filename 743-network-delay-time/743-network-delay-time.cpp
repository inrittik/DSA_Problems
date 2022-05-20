class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[n+1];
        
        for(auto it:times){
            int a = it[0], b = it[1], wt = it[2];
            g[a].push_back(make_pair(b, wt));
        }
        
        vector<int> distTo(n+1, INT_MAX);
        distTo[k] = 0; distTo[0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push(make_pair(0, k));
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            if(distTo[prev]<dist) continue;
            for(auto it:g[prev]){
                int next = it.first;
                int next_dist = it.second;
                if(distTo[next]>distTo[prev]+next_dist){
                    distTo[next] = distTo[prev]+next_dist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        int mxDelay = *max_element(distTo.begin(), distTo.end());
        return mxDelay==INT_MAX?-1:mxDelay;
    }
};