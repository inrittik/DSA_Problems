// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<int, bool> mp;
    bool helper(string s, set<string>& st, int i){
        if(i==s.size()) return true;
        if(mp.count(i)) return mp[i];
        string temp;
        for(int k=i; k<s.size(); ++k){
            temp.push_back(s[k]);
            if(st.find(temp)!=st.end()) if(helper(s, st, k+1)) return mp[i]=true;
        }
        
        return mp[i]=false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        set<string> st;
        for(auto word:B){
            st.insert(word);
        }
        return helper(A, st, 0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends