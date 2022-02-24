// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

// Geeksforgeeks - Number of trailing zeroes in factorial

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int count=0;
        while(N!=0){
            N/=5;
            count+=N;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends