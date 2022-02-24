// Leetcode - Maximum Area of Island 695

class Solution {
public:
    int getMax(vector<vector<int>>& grid, int row, int col){
        if(row<0 || col<0 || row==grid.size() || col==grid[0].size() || grid[row][col]==0){
            return 0;
        }
        grid[row][col]=0;
        return 1+getMax(grid, row-1, col)+getMax(grid, row, col-1)+getMax(grid, row+1, col)+getMax(grid, row, col+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==1){
                    mx=max(mx, getMax(grid, i, j));
                }
            }
        }
        return mx;
    }
};