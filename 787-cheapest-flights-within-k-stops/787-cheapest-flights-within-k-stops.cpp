class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(auto fl:flights){
            g[fl[0]].push_back({fl[1], fl[2]});  
        }
        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        int mnDist = INT_MAX;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            if(node[1]==dst) return node[0];
            if(dist[node[1]]<node[2]) continue;
            dist[node[1]]=node[2];
            
            if(node[2]>k) continue;
            for( auto it : g[node[1]] )
                    pq.push({ node[0]+it.second, it.first, node[2]+1 });
        }
        
        return -1;
    }
};