class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,-1));
        q.push({0, 0, 0, k});

        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            int i = fr[0];
            int j = fr[1];
            int dis = fr[2];
            int cK = fr[3];

            if(i<0 || i>m-1 || j<0 || j>n-1) continue;

            if(i==m-1 && j==n-1) return dis;

            if(grid[i][j]){
                if(cK>0) cK--;
                else continue;
            }
            if(vis[i][j]!=-1 && vis[i][j]>=cK){
                continue;
            }
            vis[i][j] = cK;
            q.push({i+1, j, dis+1, cK});
            q.push({i-1, j,dis+1, cK});
            q.push({i, j+1,dis+1, cK});
            q.push({i, j-1, dis+1,cK});
        }
        return -1;
    }
};