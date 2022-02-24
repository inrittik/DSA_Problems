// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Geeksforgeeks - A Simple Fraction

class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    // Code here
	    string ans;
	    ans = to_string(numerator/denominator);
	    int decimal=numerator%denominator;
	    if(decimal==0) return ans;
	    ans.push_back('.');
	    unordered_map<int, int> mp;
	    while(decimal!=0){
	        if(mp.count(decimal)){
	            ans.insert(mp[decimal], "(");
	            ans+=")";
	            return ans;
	        }
	        else{
	            mp[decimal]=ans.length();
	            decimal*=10;
	            int q=decimal/denominator;
	            decimal%=denominator;
	            ans+=to_string(q);
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends