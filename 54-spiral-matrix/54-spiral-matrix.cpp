class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0, t=0, r=m-1, b=n-1;
        while(t<=b && l<=r){
            int i=l;
            while(i<=r){
                spiral.push_back(matrix[t][i++]);
            }
            t++;
            
            i=t;
            while(i<=b){
                spiral.push_back(matrix[i++][r]);
            }
            r--;
            
            if(t<=b){
                i=r;
                while(i>=l){
                    spiral.push_back(matrix[b][i--]);
                }
            }
            b--;
            
            if(l<=r){
                i=b;
                while(i>=t){
                    spiral.push_back(matrix[i--][l]);
                }
            }
            l++;            
        }
        
        return spiral;
    }
};