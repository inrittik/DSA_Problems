class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a,b;
        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img2.size(); j++){
                if(img1[i][j] == 1) a.push_back({i,j});
                if(img2[i][j] == 1) b.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        int ans = 0;
        for(auto x : a){
            for(auto y : b){
                int it1 = x.first - y.first;
                int it2 = x.second - y.second;
                mp[{it1,it2}]++;
                ans = max(ans,mp[{it1,it2}]);
            }
        }
        return ans;
    }
};