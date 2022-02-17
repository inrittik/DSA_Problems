// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

// Geeksforgeeks - Minimum Number of deletions to make string palindrome
// Leetcode - Minimum Insertion Steps to Make a String Palindrome(same logic)

int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; ++i){
            dp[i][0]=0;
        }
        for(int j=0; j<=m; ++j){
            dp[0][j]=0;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
int minDeletions(string str, int n) { 
    //complete the function here 
    string B;
    for(int i=n-1; i>=0; --i){
        B.push_back(str[i]);
    }
    return n-longestCommonSubsequence(str, B);
} 