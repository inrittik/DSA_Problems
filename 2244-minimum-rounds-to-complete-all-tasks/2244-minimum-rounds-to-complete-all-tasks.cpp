class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int t:tasks) mp[t]++;
        
        int ans = 0;
        for(auto it:mp){
            if(it.second<2) return -1;
            else if(it.second%3==0) ans+=it.second/3;
            else ans+=it.second/3 + 1;
        }
        return ans;
    }
};