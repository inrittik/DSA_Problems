class Solution {
public:
    void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        int n=s.size();
        int i=0, j=0;
        while(j<n){
            if(j==n-1){
                reverse(s, i, j);
                j++;
            }
            else if(s[j]!=' '){
                j++;
            }
            else{
                reverse(s, i, j-1);
                j++;
                i=j;
            }
        }
        return s;
    }
};