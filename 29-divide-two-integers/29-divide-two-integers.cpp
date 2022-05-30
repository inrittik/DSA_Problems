class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long quo=0;
        long long dvd, dvs;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        dvd=abs(dividend);
        dvs=abs(divisor);
        while(dvd>=dvs){
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            quo += m;
        }
        return sign*quo;
    }
};