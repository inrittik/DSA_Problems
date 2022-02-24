// Leetcode - Flood Fill 733

class Solution {
public:
    void floodfill(vector<vector<int>>& image, int sr, int sc, int newColor, int color){
        if(sr<0 || sc<0 || sr==image.size() || sc==image[0].size() || image[sr][sc]!=color){
            return;
        }
        image[sr][sc]=newColor;
        floodfill(image, sr, sc-1, newColor, color);
        floodfill(image, sr-1, sc, newColor, color);
        floodfill(image, sr, sc+1, newColor, color);
        floodfill(image, sr+1, sc, newColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
        if(color==newColor) return image;
        floodfill(image, sr, sc, newColor, color);
        return image;
    }
};