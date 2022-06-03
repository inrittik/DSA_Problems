class NumMatrix {
public:
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        sumMatrix.resize(n, vector<int>(m));
        
        for(int i=0; i<n; ++i){
            int preSum=0;
            for(int j=0; j<m; ++j){
                preSum+=matrix[i][j];
                sumMatrix[i][j]=preSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1; i<=row2; ++i){
            if(col1>0){
                ans+=(sumMatrix[i][col2]-sumMatrix[i][col1-1]);
            }
            else{
                ans+=(sumMatrix[i][col2]);
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */