// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Geeksforgeeks - Egg Dropping Problem
class Solution
{
    public:
    vector<vector<int>> dp;
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n, int k){
        if(k==0 || k==1) return k;
        if(n==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int temp, mn=INT_MAX;
        for(int f=1; f<=k; ++f){
            temp=max(solve(n-1, f-1), solve(n, k-f))+1;
            mn=min(temp, mn);
        }
        return dp[n][k]=mn;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        dp.resize(n+1, vector<int>(k+1, -1));
        return solve(n, k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends