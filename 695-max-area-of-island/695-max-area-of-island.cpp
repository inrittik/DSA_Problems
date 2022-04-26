class Solution {
public:
    int findArea(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x==grid.size() || y<0 || y==grid[0].size() || grid[x][y]!=1){
            return 0;
        }
        grid[x][y] = 0;
        int area = findArea(grid, x-1, y)+findArea(grid, x, y-1)+findArea(grid, x+1, y)+findArea(grid, x, y+1)+1;
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = INT_MIN;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    mx = max(mx, findArea(grid, i, j));
                }
            }
        }
        return mx==INT_MIN?0:mx;
    }
};