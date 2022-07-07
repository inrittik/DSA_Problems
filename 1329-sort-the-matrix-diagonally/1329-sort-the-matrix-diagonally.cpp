class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        unordered_map<int, multiset<int>> mp;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                mp[i-j].insert(matrix[i][j]);
            }
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                matrix[i][j]=*mp[i-j].begin();
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        
        return matrix;
    }
};