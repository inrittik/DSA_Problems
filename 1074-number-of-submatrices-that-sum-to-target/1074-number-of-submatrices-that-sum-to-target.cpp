class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre = matrix;
        for(int i=0; i<n; ++i){
            for(int j=1; j<m; ++j){
                pre[i][j] += pre[i][j-1];
            }
        }
        int res = 0;
        for(int colS = 0; colS<m; ++colS){
            for(int colE = colS; colE<m; ++colE){
                for(int rowS = 0; rowS<n; ++rowS){
                    int sum = 0;
                    for(int rowE = rowS; rowE < n; ++rowE){
                        int preEnd = pre[rowE][colE];
                        int preStart = colS==0? 0:pre[rowE][colS - 1];
                        sum += preEnd - preStart;
                        if(sum == target) res++;
                    }
                }
            }
        }
        
        return res;
    }
};