// all permutations of a string(input list is unique)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	// backtracking solution
    public:
        void permutations(vector<string> &permVector, string S, int i, int n){
            if(i==n){
                permVector.push_back(S);
            }
            else{
                for(int j=i; j<n; ++j){
                    swap(S[i], S[j]);
                    permutations(permVector, S, i+1, n);
                    swap(S[i], S[j]);
                }
            }
        }
        
    // recursion solution
    public:
    	void permut(vector<string> &permVector, string S, string osf){
    		if(S.size()==0){
    			permVector.push_back(osf);
    		}
    		else{
    			for(int i=0; i<S.size(); ++i){
    				char ch = S[i];
    				string ros = S.substr(0, i) + S.substr(i+1);
    				permut(permVector, ros, osf+ch);
    			}
    		}
    	}
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> permVector;
      //       int n = S.size();
		    // permutations(permVector, S, 0, n);
		    permut(permVector, S, "");
		    return permVector;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}