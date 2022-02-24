// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

// Geeksforgeeks - Longest K unique characters substring

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        unordered_map<char, int> mp;
        int n=s.size();
        int i=0, j=0;
        int mx=0, unique=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<k){
                j++;
            }
            else if(mp.size()==k){
                mx=max(mx, j-i+1);
                j++;
            }
            else{
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(mx==0 || mp.size()<k) return -1;
        return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends