// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Geeksforgeeks - Perfect Sum problem

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        long long max=1e9+7;
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
                    dp[i][j]=(dp[i-1][j]%max+dp[i-1][j-arr[i-1]]%max)%max;
                }
                else{
                    dp[i][j]=dp[i-1][j]%max;
                }
            }
        }
        return dp[n][sum]%max;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends