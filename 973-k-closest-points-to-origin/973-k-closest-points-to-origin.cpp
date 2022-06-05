typedef pair<double, pair<int, int>> ppd;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<double> dist(n);
        for(int i=0; i<n; ++i){
            int x = pow(points[i][0],2);
            int y = pow(points[i][1],2);
            dist[i] = sqrt(x+y);
        }
        
        priority_queue<ppd> pq;
        for(int i=0; i<n; ++i){
            pq.push({dist[i], {points[i][0], points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(pq.size()>0){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};