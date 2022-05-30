class Solution {
public:
    int myAtoi(string s) {
        int start;
        int i=0;
        int sign=1;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+') {
            sign=1;
            i++;
        }
        int val=0;
        while (s[i] >= '0' && s[i] <= '9') {
            if (val>INT_MAX / 10 || (val == INT_MAX / 10 && s[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            val  = 10 * val + (s[i++] - '0');
        }
        
        return sign*val;
    }
};