class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> v;
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int live=0, dead=0;
                if(i-1>=0){
                    if(board[i-1][j]==1) live++;
                    else dead++;
                }
                if(i+1<n){
                    if(board[i+1][j]==1) live++;
                    else dead++;
                }
                if(j-1>=0){
                    if(board[i][j-1]==1) live++;
                    else dead++;
                }
                if(j+1<m){
                    if(board[i][j+1]==1) live++;
                    else dead++;
                }
                if(i-1>=0 && j-1>=0){
                    if(board[i-1][j-1]==1) live++;
                    else dead++;
                }
                if(i-1>=0 && j+1<m){
                    if(board[i-1][j+1]==1) live++;
                    else dead++;
                }
                if(i+1<n && j-1>=0){
                    if(board[i+1][j-1]==1) live++;
                    else dead++;
                }
                if(i+1<n && j+1<m){
                    if(board[i+1][j+1]==1) live++;
                    else dead++;
                }
                if(board[i][j]==1){
                    if(live<2 || live>3){
                        v.push_back({i, j});
                    }
                }
                else{
                    if(live==3){
                        v.push_back({i, j});
                    }
                }
            }
        }
        int t=v.size();
        for(int i=0; i<t; ++i){
            board[v[i].first][v[i].second]=(board[v[i].first][v[i].second]+1)%2;
        }
    }
};