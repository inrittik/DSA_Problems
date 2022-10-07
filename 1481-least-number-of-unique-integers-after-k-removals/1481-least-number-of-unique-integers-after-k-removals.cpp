class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int total = 0;
        for(int a:arr) {
            if(mp.count(a)==0) total++;
            mp[a]++;
        }
        vector<int> v;
        for(auto it:mp) v.push_back(it.second);
        sort(v.begin(), v.end());
        int rem = 0;
        for(int i:v){
            if(i<=k){
                k-=i;
                rem++;
            }
            else break;
        }
        return total - rem;
    }
};