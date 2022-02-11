// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

// Geeksforgeeks - Subsetsum problem

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool dp[N+1][sum+1];
        for(int i=0; i<=N; ++i){
            for(int j=0; j<=sum; ++j){
                if(i==0)dp[i][j]=false;
                if(j==0)dp[i][j]=true;
            }
        }
    
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }

    // alternate
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
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
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends