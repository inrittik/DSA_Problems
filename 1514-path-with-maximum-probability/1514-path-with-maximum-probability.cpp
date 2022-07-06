typedef pair<int,double> pid;
typedef pair<double,int> pdi;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);
        prob[start] = 1;
        
        vector<vector<pid>> g(n);
        int size = edges.size();
        for(int i=0; i<size; ++i){
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pdi> pq;
        pq.push({1, start});
        
        while(!pq.empty()){
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            
            for(auto it:g[node]){
                if(prob[it.first]<p*it.second){
                    prob[it.first] = p*it.second;
                    pq.push({prob[it.first], it.first});
                }
            }
        }
        return prob[end];
    }
};