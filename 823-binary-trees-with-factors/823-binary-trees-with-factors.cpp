class Solution {
public:
    int mod = 1e9+7;
    unordered_map<int, int> mp;
    long long helper(vector<int>& arr, int i){
        if(mp.count(i)) return mp[i];
        long long cnt = 1;
        for(auto it:arr){
            if(it>i) break;
            else if(i%it==0 && binary_search(arr.begin(), arr.end(), i/it)){
                cnt = cnt%mod + (helper(arr, i/it)%mod*helper(arr, it)%mod)%mod;
            }
        }
        return mp[i]=cnt%mod;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int ans = 0;
        for(int it:arr){
            ans = ans%mod + helper(arr, it)%mod;
        }
        return ans%mod;
    }
};