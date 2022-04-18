class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i]==-1) return i;
        else return find(parent[i]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n, -1);
        int count = n;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(isConnected[i][j]==1){
                    int from = find(i);
                    int to = find(j);
                    
                    if(from!=to){
                        parent[from] = to;
                        count--;
                    }
                }
            }
        }
        
        return count;
    }
};