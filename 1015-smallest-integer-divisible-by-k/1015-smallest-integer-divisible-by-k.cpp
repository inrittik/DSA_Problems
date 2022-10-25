class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k==5) return -1;
        int i = 1;
        int num = 1;
        while(i<=k){
            if(num%k==0) return i;
            num = (num*10)%k + 1%k;
            i++;
        }
        return -1;
    }
};