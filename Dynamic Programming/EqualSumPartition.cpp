// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Geeksforgeeks - Equal Sum partition

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; ++i) sum+=arr[i];
        if(sum%2!=0) return false;
        sum/=2;
        int dp[N+1][sum+1];
        for(int j=0; j<=sum; ++j){
            dp[0][j]=0;
        }
        for(int i=0; i<=N; ++i){
            dp[i][0]=1;
        }
        
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1]<=j){
                    if(dp[i-1][j] || dp[i-1][j-arr[i-1]]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[N][sum]) return true;
        else return false;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends