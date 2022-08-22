class Solution {
public:
    bool isPowerOfFour(int num) {
        long long n = num;
        if(n==2 || n==0) return false;
        if((n&(n-1))==0){
            n = sqrt(n);
            if(n*n != num) return false;
            if((n&(n-1))==0) return true;
        }
        return false;
    }
};