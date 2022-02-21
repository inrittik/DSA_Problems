// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Geeksforgeeks - Palindrome Partitioning

class Solution{
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int i, int j){
        if(i>=j) return true;
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string &s, int i, int j){
        int temp, mn=INT_MAX;
        if(i>=j || isPalindrome(s, i, j)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            for(int k=i; k<=j-1; ++k){
                int left, right;
                if(dp[i][k]!=-1){
                    left=dp[i][k];
                }
                else{
                    left=solve(s, i, k);
                    dp[i][k]=left;
                }
                if(dp[k+1][j]!=-1){
                    right=dp[k+1][j];
                }
                else{
                    right=solve(s, k+1, j);
                    dp[k+1][j]=right;
                }
                temp=left+right+1;
                mn=min(temp, mn);
            }
            return dp[i][j]=mn;
        }
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(str, 0, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends