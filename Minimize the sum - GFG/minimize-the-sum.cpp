//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i:arr) pq.push(i);
        int sum = 0;
        while(pq.size()>1){
            int t = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            sum += t+s;
            pq.push(t+s);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends