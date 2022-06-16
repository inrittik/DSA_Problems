class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> v(26);
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        left[-1] = 0;
        for(int i=0; i<n; ++i){
            if(v[s[i]-'a']==0) {
                left[i] = left[i-1]+1;
                v[s[i]-'a']++;
            }
            else left[i] = left[i-1];
        }
        right[n] = 0;
        v.clear();
        v.resize(26);
        for(int i=n-1; i>=0; --i){
            if(v[s[i]-'a']==0) {
                right[i] = right[i+1]+1;
                v[s[i]-'a']++;
            }
            else right[i] = right[i+1];
        }
        
        int ans = 0;
        for(int i=0; i<n; ++i){
            if(left[i]==right[i+1]) ans++;
        }
        return ans;
    }
};