class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i]==i) return i;
        else return find(parent[i]);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i!=j && (stones[i][0] == stones[j][0] || stones[i][1]==stones[j][1])){
                    parent[find(i)] = find(j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(parent[i]==i) cnt++;
        }
        
        return n - cnt;
    }
};