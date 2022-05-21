class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n<=1) return 0;
        int water = 0;
        int start = 0, end = n-1;
        while(start<end){
            int h = min(height[start], height[end]);
            water = max(water, h*(end-start));
            
            while(height[start]<=h and start<end) start++;
            while(height[end]<=h and start<end) end--;
        }
        
        return water;
    }
};