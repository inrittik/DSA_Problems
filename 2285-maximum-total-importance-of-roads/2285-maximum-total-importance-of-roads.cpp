class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<pair<int, int>> cnt(n, {0, 0});
        for(int i=0; i<m; ++i){
            cnt[roads[i][0]]={cnt[roads[i][0]].first+1, roads[i][0]};
            cnt[roads[i][1]]={cnt[roads[i][1]].first+1, roads[i][1]};
        }
        sort(cnt.begin(), cnt.end(), greater<pair<int,int>>());
        vector<int> values(n, 0);
        int k=n;
        for(int i=0; i<n; ++i){
            if(cnt[i].first==0) break;
            values[cnt[i].second]=k--;
        }
        long long ans=0;
        for(int i=0; i<m; ++i){
            ans+=values[roads[i][0]]+values[roads[i][1]];
        }
        return ans;
    }
};