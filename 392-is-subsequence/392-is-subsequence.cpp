class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int n=t.size();
        int m =s.size();
        if(m==1){
            while(j<n){
                if(t[j++]==s[0]) return true;
            }
            return false;
        }
        j = 0;
        while(i<m && j<n){
            while(j<n && s[i]!=t[j]) j++;
            if(j==n) break;
            i++;
            j++;
        }
        if(i==m) return true;
        else return false;
    }
};