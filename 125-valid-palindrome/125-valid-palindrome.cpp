class Solution {
public:
    bool checkPalindrome(string p){
        int i = 0, j = p.size()-1;
        
        while(i<j){
            if(p[i++]!=p[j--]) return false;
        }
        
        return true;
    }
    bool isPalindrome(string s) {
        string p;
        for(char c:s){
            if((c>='0' && c<='9')||(c>='a' && c<='z')||(c>='A' && c<='Z')){
                if(c>='A' && c<='Z'){
                    p.push_back(c-('A'-'a'));
                }
                else p.push_back(c);
            }
        }
        
        return checkPalindrome(p);
    }
};