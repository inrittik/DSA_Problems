// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int calcMultiplications(int arr[], int i, int j, vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn = INT_MAX;
        for(int k = i; k<j; ++k){
            dp[i][k] = calcMultiplications(arr, i, k, dp);
            dp[k+1][j] = calcMultiplications(arr, k+1, j, dp);
            int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
            mn = min(mn, steps);
        }
        return dp[i][j]=mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return calcMultiplications(arr, 1, N-1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends