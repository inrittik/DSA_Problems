// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int helper(int n,int m,string &s,string &t)
    {
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m]=(helper(n-1,m-1,s,t)%mod+helper(n-1,m,s,t)%mod)%mod;
        }
        return dp[n][m]=helper(n-1,m,s,t)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
        int n = s.size();
        int m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return helper(n-1, m-1, s, t)%mod;
    }
};
 


// { Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}  // } Driver Code Ends