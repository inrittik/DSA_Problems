class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int cnt = 0;
        for(int i=0; i<n; ++i) cnt += matrix[i][0];
        for(int j=1; j<m; ++j) cnt += matrix[0][j];
        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                if(matrix[i][j]==1){
                    matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + 1;
                }
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};