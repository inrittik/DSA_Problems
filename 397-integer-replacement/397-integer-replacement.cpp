class Solution {
public:
    unordered_map<int, int> dp;
    int helper(int n){
        if(n==1) return 0;
        if(dp.count(n)!=0) return dp[n];
        if(n%2==0) dp[n]=1+helper(n/2);
        else{
            dp[n]=2+min(helper(n/2), helper(n/2+1));
        }
        
        return dp[n];
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};