class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int &m, int &n, set<pair<int, int>>& s){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(grid[i][j]==2 && s.size()==0) return 1;
        else if(grid[i][j]==2 && s.size()) return 0;
        if(grid[i][j]==-1) return 0;
        
        grid[i][j]=-1;
        s.erase({i, j});
        
        int left = 0, right = 0, top = 0, bottom = 0;
        left = helper(grid, i, j-1, m, n, s);
        right = helper(grid, i, j+1, m, n, s);
        top = helper(grid, i-1, j, m, n, s);
        bottom = helper(grid, i+1, j, m, n, s);
        
        grid[i][j] = 0;
        s.insert({i, j});
        return left+right+top+bottom;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<pair<int, int>> s;
        int starti = 0, startj = 0;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1){
                    starti = i;
                    startj = j;
                }
                else if(grid[i][j]==0){
                    s.insert(make_pair(i, j));
                }
            }
        }
        
        return helper(grid, starti, startj, m, n, s);
    }
};