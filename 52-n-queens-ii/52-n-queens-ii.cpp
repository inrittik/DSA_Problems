class Solution {
public:
    int cnt = 0;
    vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &board, int row){
        if(row == board.size()){
            ret.push_back(board);
            cnt++;
            return;
        }
        for(int i=0;i<board.size();++i){
            if(is_valid(board,row,i)){
                board[row][i] = 'Q';
                dfs(board,row+1);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return cnt;
    }
};