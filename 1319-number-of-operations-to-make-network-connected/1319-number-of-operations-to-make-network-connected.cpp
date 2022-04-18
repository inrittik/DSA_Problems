class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        else return parent[x] = find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c = connections.size();
        parent.resize(n); // parent for all the computers
        vector<int> rank(n, 0);
        if(c<n-1) return -1; // number of connections should be atleast n-1
        for(int i=0; i<n; ++i) parent[i]=i;
        int cnt = 0;
        for(int i=0; i<c; ++i){ // loop for evaluating all the connections
            int u = find(connections[i][0]);
            int v = find(connections[i][1]);
            // make union
            if(u!=v){
                if(rank[u]>rank[v]){
                    parent[v] = u;
                }
                else if(rank[v]<rank[u]){
                    parent[u] = v;
                }
                else{
                    parent[u] = v;
                    rank[u]++;
                }
            }
        }
        for(int i=0; i<n; ++i){
            if(parent[i]==i) cnt++; // cnt total number of disjoint set
        }
        return cnt-1; // one disjoint set is the completed network
    }
};