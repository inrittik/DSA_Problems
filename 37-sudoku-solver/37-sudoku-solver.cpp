class Solution {
public:
    int N=9;
    bool isSafe(vector<vector<char>>& board, int row, int col, char key){
        for(int i=0; i<N; ++i){
            if(board[row][i]==key) return false;
        }
        for(int i=0; i<N; ++i){
            if(board[i][col]==key) return false;
        }
        row/=3;
        col/=3;
        row*=3;
        col*=3;
        for(int i=row; i<row+3; ++i){
            for(int j=col; j<col+3; ++j){
                if(board[i][j]==key) return false;
            }
        }
        return true;
    }
    bool isPossible(vector<vector<char>>& board, int row, int col){
        if(row==N){
            return true;
        }
        if(col==N){
            return isPossible(board, row+1, 0);
        }
        if(board[row][col]!='.'){
            return isPossible(board, row, col+1);
        }
        for(char i='1'; i<='9'; ++i){
            if(isSafe(board, row, col, i)){
                board[row][col]=i;
                if(isPossible(board, row, col+1)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        isPossible(board, 0, 0);
    }
};