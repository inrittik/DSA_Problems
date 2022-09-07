class Solution {
public:
    bool checkValidString(string s) {
        int op = 0, cl = 0;
        for(char c: s){
            if(c=='(') {
                op++;
                cl++;
            }
            else if(c==')'){
                op--;
                cl--;
            }
            else if(c=='*'){
                op++;
                cl--;
            }
            if(op<0) return false;
            if(cl<0) cl=0;
        }
        return cl==0;
    }
};