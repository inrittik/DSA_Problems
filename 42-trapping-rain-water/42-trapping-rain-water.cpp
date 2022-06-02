class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxToLeft(n);
        vector<int> maxToRight(n);
        int mx=-1;
        for(int i=0; i<n; ++i){
            maxToLeft[i]=mx;
            mx=max(mx, height[i]);
        }
        mx=-1;
        for(int j=n-1; j>=0; --j){
            maxToRight[j]=mx;
            mx=max(mx, height[j]);
        }
        int ans=0;
        for(int i=0; i<n; ++i){
            if(maxToLeft[i]>height[i] && maxToRight[i]>height[i]){
                ans+=(min(maxToLeft[i], maxToRight[i]) - height[i]);
            }
        }
        
        return ans;
    }
};