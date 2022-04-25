class Solution {
public:
    void checkDFS(vector<vector<char>>& grid, int x, int y){
        if(x<0 || x==grid.size() || y<0 || y==grid[0].size() || grid[x][y]!='1'){
            return;
        }
        grid[x][y] = '0';
        checkDFS(grid, x-1, y);
        checkDFS(grid, x, y-1);
        checkDFS(grid, x+1, y);
        checkDFS(grid, x, y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1'){
                    checkDFS(grid, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};