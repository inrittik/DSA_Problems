class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        
        int i=1;
        int top = 0, bottom = n-1, left = 0, right = n-1;
        while(i<=n*n){
            for(int j=left; j<=right; j++){
                mat[top][j] = i++;
            }
            top++;
            for(int j=top; j<=bottom; ++j){
                mat[j][right] = i++;
            }
            right--;
            for(int j=right; j>=left; --j){
                mat[bottom][j] = i++;
            }
            bottom--;
            for(int j=bottom; j>=top; --j){
                mat[j][left] = i++;
            }
            left++;
        }
        
        return mat;
    }
};