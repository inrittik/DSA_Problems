class Solution {
public:
    void fillDFS(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x==grid.size() || y<0 || y==grid[0].size() || grid[x][y]==0){
            return;
        }
        grid[x][y] = 0;
        fillDFS(grid, x-1, y);
        fillDFS(grid, x, y-1);
        fillDFS(grid, x+1, y);
        fillDFS(grid, x, y+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        fillDFS(grid, i, j);
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};