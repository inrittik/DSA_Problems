class Solution {
public:
    void fillY(vector<vector<char>>& b, int x, int y){
        if(x<0 || y<0 || x==b.size() || y==b[0].size() || b[x][y]!='O'){
            return;
        }
        b[x][y] = 'Y';
        fillY(b, x-1, y);
        fillY(b, x, y-1);
        fillY(b, x+1, y);
        fillY(b, x, y+1);
    }
    void fillX(vector<vector<char>>& b, int x, int y){
        if(b[x][y]!='O'){
            return;
        }
        b[x][y] = 'X';
        fillX(b, x-1, y);
        fillX(b, x, y-1);
        fillX(b, x+1, y);
        fillX(b, x, y+1);
    }
    void fillO(vector<vector<char>>& b, int x, int y){
        if(x<0 || y<0 || x==b.size() || y==b[0].size() || b[x][y]!='Y'){
            return;
        }
        b[x][y] = 'O';
        fillO(b, x-1, y);
        fillO(b, x, y-1);
        fillO(b, x+1, y);
        fillO(b, x, y+1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j]=='O'){
                    if(i==0 || j==0 || i==n-1 || j==m-1){
                        fillY(board, i, j);
                    }
                }
            }
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j]=='O'){
                    fillX(board, i, j);
                }
            }
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j]=='Y'){
                    fillO(board, i, j);
                }
            }
        }
    }
};