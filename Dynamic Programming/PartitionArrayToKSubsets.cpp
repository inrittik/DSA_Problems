// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

// Geeksforgeeks - Partition Array To K Subsets

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int range=0;
         sort(a, a+n);
         for(int i=0; i<n; ++i) range+=a[i];
         int sum = range/k;
         if(range%k!=0 || a[n-1]>sum) return false;
         if(k==1) return true;
         else{
            int dp[n+1][sum+1];
            for(int j=0; j<=sum; ++j){
                dp[0][j]=0;
            }
            for(int i=0; i<=n; ++i){
                dp[i][0]=1;
            }
            
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=sum; ++j){
                    if(a[i-1]<=j){
                        if(dp[i-1][j] || dp[i-1][j-a[i-1]]){
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
            if(dp[n][sum]) return true;
            else return false;
         }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends