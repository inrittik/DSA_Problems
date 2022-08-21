class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int m = grid.size();
        int n = grid[0].size();
        bool isPresent = false;
        bool isGood = false;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==2){
                    q.push({i, j});
                    isPresent = true;
                }
                else if(grid[i][j]==1){
                    isGood = true;
                }
            }
        }
        if(!isPresent && !isGood) return 0;
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            cnt++;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                if(r>0 && grid[r-1][c]==1){
                    q.push({r-1, c});
                    grid[r-1][c]=2;
                }
                if(r<m-1 && grid[r+1][c]==1){
                    q.push({r+1, c});
                    grid[r+1][c]=2;
                }
                if(c>0 && grid[r][c-1]==1){
                    q.push({r, c-1});
                    grid[r][c-1]=2;
                }
                if(c<n-1 && grid[r][c+1]==1){
                    q.push({r, c+1});
                    grid[r][c+1]=2;
                }
            }
        }
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return cnt-1;
    }
};