// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

// Geeksforgeeks - Target Sum

class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
    int range=0;
    int n = arr.size();
    for(int i=0; i<n; ++i) range+=arr[i];
    int sum = range+target;
    if(sum%2==1) return 0;
    else{
        sum/=2;
        long long dp[n+1][sum+1];
        for(int i=0;i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(i==0) dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends