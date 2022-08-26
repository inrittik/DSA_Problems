class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int mxLen = 0;
        int mxOc = 0;
        while(j<n){
            mp[s[j]]++;
            mxOc = max(mxOc, mp[s[j]]);
            int len = j-i+1;
            if(len-mxOc==k){
                mxLen = max(mxLen, len);
            }
            else if(len-mxOc>k){
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return mxLen==0?n:mxLen;
    }
};