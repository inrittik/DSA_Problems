// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
        int mod = 1e9+7;
		int CountWays(string s){
		    // Code here
            if(s[0]=='0') return 0;
            vector<int> dp(s.length());
            dp[0]=1;
            int num = 10*int(s[0]-'0')+int(s[1]-'0');
            if(num<=26) {
                dp[1]=(s[1]=='0'?1:2);
            }
            else{
                dp[1]=(s[1]=='0'?0:1);
            }
            for(int i=2; i<s.size(); ++i){
                dp[i]=(s[i]=='0'?0:dp[i-1]);
                num = 10*int(s[i-1]-'0')+int(s[i]-'0');
                if(num>=1 && num<=26 && s[i-1]!='0'){
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }
            return dp[s.size()-1];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends