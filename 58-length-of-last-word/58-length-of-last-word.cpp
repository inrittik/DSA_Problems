class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=0;
        int ans = 0;
        int start = 0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            start = i;
            while(i<n && s[i]!=' ') i++;
            if(i<n) ans = i-start;
        }
        if(s[n-1]!=' ') ans = n-start;
        return ans;
    }
};