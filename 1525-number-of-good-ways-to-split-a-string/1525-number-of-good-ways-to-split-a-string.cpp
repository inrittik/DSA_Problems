class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> v1(26);
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        left[-1] = 0;
        for(int i=0; i<n; ++i){
            if(v1[s[i]-'a']==0) {
                left[i] = left[i-1]+1;
                v1[s[i]-'a']++;
            }
            else left[i] = left[i-1];
        }
        right[n] = 0;
        vector<int> v2(26);
        for(int i=n-1; i>=0; --i){
            if(v2[s[i]-'a']==0) {
                right[i] = right[i+1]+1;
                v2[s[i]-'a']++;
            }
            else right[i] = right[i+1];
        }
        
        int ans = 0;
        for(int i=0; i<n; ++i){
            if(left[i]==right[i+1]) ans++;
            // cout<<left[i]<<" "<<right[i]<<endl;
        }
        return ans;
    }
};