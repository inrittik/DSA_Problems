class Solution {
public:
    bool isPalindrome(string s){
        int l=0;
        int h=s.size()-1;
        
        while(l<h){
            if(s[l++]!=s[h--]) return false;
        }
        
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindrome(s)){
            return 1;
        }
        else return 2;
    }
};