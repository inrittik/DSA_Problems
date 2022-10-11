class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int x:arr) mp[(x%k + k)%k]++;
        for(int i=0; i<k; ++i){
            if(i==0) {
                if(mp[i]%2!=0) return false; 
            }
            else if(mp[i]!=mp[k-i]) return false;
        }
        return true;
    }
};