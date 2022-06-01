class Solution {
public:
    int MAH(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n);
        vector<int> left(n);
        
        stack<int> st;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            
            st.push(i);
        }
        
        int mxArea=INT_MIN;
        
        for(int i=0; i<n; ++i){
            int area = (right[i]-left[i]-1)*heights[i];
            mxArea = max(mxArea, area);
        }
        
        return mxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m, 0);
        vector<int> areas(n);
        int mxArea = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j]=='0') heights[j]=0;
                else heights[j]+=1;
            }
            
            mxArea = max(mxArea, MAH(heights));
        }
        
        return mxArea;
    }
};