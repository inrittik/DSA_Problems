class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1) return "";
        else{
            bool flag = false;
            for(int i=0; i<p.size()/2; ++i){
                if(p[i]>'a'){
                    flag = true;
                    p[i] = 'a';
                    break;
                }
            }
            if(!flag) p[p.size()-1] += 1;
            return p;
        }
    }
};