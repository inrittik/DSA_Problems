class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r = r*10 + n%10;
            n = n/10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        for(int i:nums){
            int r = rev(i);
            s.insert(r);
        }
        return s.size();
    }
};