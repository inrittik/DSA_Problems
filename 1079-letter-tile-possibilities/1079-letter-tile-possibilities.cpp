class Solution {
public:
    void helper(string& tiles, unordered_map<string,int>&mp, int n, string& p){
        if(n==tiles.size()) return;
        int s = p.size();
        string og = p;
        for(int i=0; i<=s; ++i){
            p.insert(i,1,tiles[n]);
            // cout<<p<<endl;
            if(!mp.count(p)){
                mp[p]++;
                helper(tiles,mp,n+1,p);
            }
            p = og;
        }
        helper(tiles,mp,n+1,p);
    }
    int numTilePossibilities(string tiles) {
        unordered_map<string,int> mp;
        string p = "";
        helper(tiles, mp, 0, p);
        // for(auto it:mp) cout<<it.first<<endl;
        return mp.size();
    }
};