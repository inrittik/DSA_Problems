class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int last = str.size();
        for(int i=last-1; i>0; --i){
            if(str[i]<str[i-1]){
                last = i;
                str[i-1] = str[i-1]-1;
            }
        }
        for(int i=last; i<str.size(); ++i) str[i] = '9';
        return stoi(str);
    }
};