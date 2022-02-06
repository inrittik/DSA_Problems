// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


// generate sequence of gray code for any integer n<=16 i.e. every next binary string should differ by exactly 1 bit to the previous string

class Solution
{
    public:
    void generateGray(int n, int prev, vector<string> &seq, string osf){
        if(n==0){
            seq.push_back(osf);
            return;
        }
        else{
            if(prev==0){
                generateGray(n-1,0, seq, osf+'0');
                generateGray(n-1,1, seq, osf+'1');
            }
            else if(prev==1){
                generateGray(n-1,0, seq, osf+'1');
                generateGray(n-1,1, seq, osf+'0');
            }
            
        }
    }
    public:
    vector<string> graycode(int n)
    {
        //code here
        vector<string> seq;
        generateGray(n,0, seq, "");
        return seq;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends