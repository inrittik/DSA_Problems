class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(128);
        
        for(char c:s){
            v[c]++;
        }

        int odd = 0;
        for(int i=0; i<128; ++i){
            if(v[i]%2!=0){
                odd++;
            }
        }
        
        return s.size() - odd + (odd>0);
    }
};