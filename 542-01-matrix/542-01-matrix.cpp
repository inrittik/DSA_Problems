class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int inf = m * n;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]==0) continue;
                else{
                    int up = inf, left = inf;
                    if(i-1>=0) up = mat[i-1][j];
                    if(j-1>=0) left = mat[i][j-1];
                    
                    mat[i][j] = min(up, left)+1;
                }
            }
        }
        
        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                if(mat[i][j]==0) continue;
                else{
                    int down = inf, right = inf;
                    if(i+1<n) down = mat[i+1][j];
                    if(j+1<m) right = mat[i][j+1];
                    
                    mat[i][j] = min(min(down, right)+1, mat[i][j]);
                }
            }
        }
        
        return mat;
    }
};