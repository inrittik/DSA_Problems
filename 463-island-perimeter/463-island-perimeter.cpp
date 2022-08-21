class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int r = 0, c = 0;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1){
                    r = i; c= j;
                    break;
                }
            }
        }
        
        int peri = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> vis(m, vector<int>(n));
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int sides = 4;
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(vis[r][c]) continue;
                
                if(r>0 && grid[r-1][c]==1){
                    sides--;
                    q.push({r-1, c});
                }
                if(r<m-1 && grid[r+1][c]==1){
                    sides--;
                    q.push({r+1, c});
                }
                if(c>0 && grid[r][c-1]==1){
                    sides--;
                    q.push({r, c-1});
                }
                if(c<n-1 && grid[r][c+1]==1){
                    sides--;
                    q.push({r, c+1});
                }
                
                peri += sides;
                vis[r][c] = 1;
            }
        }
        
        return peri;
    }
};