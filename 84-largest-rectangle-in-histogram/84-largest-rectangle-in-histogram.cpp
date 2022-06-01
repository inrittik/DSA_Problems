class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n);
        vector<int> left(n);
        
        stack<int> nsr;
        stack<int> nsl;
        
        for(int i=0; i<n; ++i){
            while(!nsl.empty() && heights[nsl.top()]>=heights[i]){
                nsl.pop();
            }
            if(nsl.empty()){
                left[i]=-1;
            }
            else{
                left[i]=nsl.top();
            }
            
            nsl.push(i);
        }
        
        for(int i=n-1; i>=0; --i){
            while(!nsr.empty() && heights[nsr.top()]>=heights[i]){
                nsr.pop();
            }
            if(nsr.empty()){
                right[i]=n;
            }
            else{
                right[i]=nsr.top();
            }
            
            nsr.push(i);
        }
        
        int mxArea=INT_MIN;
        
        for(int i=0; i<n; ++i){
            int area = (right[i]-left[i]-1)*heights[i];
            mxArea = max(mxArea, area);
        }
        
        return mxArea;
    }
};