class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1]) return a[0]<=b[0];
        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int last = pairs[0][1];
        int ans = 1;
        for(auto p:pairs){
            if(p[0]>last){
                ans++;
                last = p[1];
            }
        }
        return ans;
    }
};