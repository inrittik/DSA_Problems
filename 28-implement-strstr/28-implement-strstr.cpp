class Solution {
public:
    bool equal(string s, string t, int i){
        int k=0;
        if(i+t.size()-1>=s.size()) return false;
        while(i+k<s.size() && k<t.size()){
            if(s[i+k]!=t[k]) return false;
            k++;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.length(), m=needle.length();
        if(n<m || m==0) return -1;
        for(int i=0; i<n; ++i){
            if(haystack[i]==needle[0]){
                if(equal(haystack, needle, i)) return i;
            }
        }
        return -1;
    }
};