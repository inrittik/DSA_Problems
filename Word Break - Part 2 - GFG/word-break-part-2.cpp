// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    void helper(string& s, string osf, set<string>& st, int i){
        if(i==s.size()){
            ans.push_back(osf);
            return;
        }
        if(osf.size()>0) osf+=" ";
        string temp = "";
        for(int k=i; k<s.size(); ++k){
            temp.push_back(s[k]);
            if(st.find(temp)!=st.end()){
                helper(s, osf+temp, st, k+1);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        set<string> st;
        for(auto word:dict){
            st.insert(word);
        }
        helper(s, "", st, 0);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends