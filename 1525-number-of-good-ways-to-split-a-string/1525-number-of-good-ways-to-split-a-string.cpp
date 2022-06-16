class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> left(n), right(n);
        unordered_map<char, int> m1,m2;
        for(int i=0; i<n; ++i){
            m1[s[i]]++;
            m2[s[n-1-i]]++;
            
            left[i] = m1.size();
            right[n-1-i] = m2.size();
        }
        int ans = 0;
        for(int i=1; i<n; ++i){
            if(left[i-1]==right[i]) ans++;
        }
        return ans;
    }
};