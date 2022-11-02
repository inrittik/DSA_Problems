class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mn = INT_MAX;
        unordered_map<int,int> mp;
        int n = cards.size();
        for(int i=0; i<n; ++i){
            if(mp.count(cards[i])) {
                mn = min(mn, i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        return mn==INT_MAX?-1:mn;
    }
};