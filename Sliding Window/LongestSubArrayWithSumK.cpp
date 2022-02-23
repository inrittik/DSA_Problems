// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Geeksforgeeks - Longest Subarray with sum K

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mp;
        int i=0, sum=0;
        int mx=0;
        while(i<N){
            sum+=A[i];
            if(sum==K){
                mx=i+1;
            }
            if(mp.find(sum)==mp.end()){
                mp.insert({sum, i});
            }
            if(mp.find(sum-K)!=mp.end()){
                mx=max(mx, i-mp[sum-K]);
            }
            i++;
        }
        return mx;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends