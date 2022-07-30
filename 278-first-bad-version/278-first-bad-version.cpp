// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while(hi-lo>1){
            int mid = (hi-lo)/2+lo;
            if(isBadVersion(mid)){
                hi = mid;
            }
            else lo = mid+1;
        }
        
        if(isBadVersion(lo)) return lo;
        else return hi;
    }
};