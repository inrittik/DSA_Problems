class Solution {
public:
    int findOc(string &s, int l, int u){
        unordered_map<string, int> mp;
        unordered_map<char, int> cmp;
        int mx = 0, n = s.size();
        int i=0, j = 0;
        while(j<n){
            cmp[s[j]]++;
            if((j-i+1)==l){
                if(cmp.size()<=u){
                    mx = max(mx, ++mp[s.substr(i, l)]);
                }
                if(--cmp[s[i]]==0) cmp.erase(s[i]);
                i++;
            }
            j++;
        }
        return mx;
    }
    int maxFreq(string s, int mxL, int mnS, int mxS) {
        int mxOc = 0;
        for(int i=mnS; i<=mxS; ++i){
            mxOc = max(mxOc, findOc(s, i, mxL));
        }
        return mxOc;
    }
};