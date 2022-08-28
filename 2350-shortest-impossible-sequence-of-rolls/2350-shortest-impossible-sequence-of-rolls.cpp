class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        unordered_map<int,int> mp;
        int sz = 0;
        for(int i=0; i<n; i++){
            mp[rolls[i]]++;
            if(mp.size()==k){
                sz++;
                mp.clear();
            }
        }
        return sz+1;
    }
};