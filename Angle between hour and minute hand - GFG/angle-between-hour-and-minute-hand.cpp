//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getAngle(int H , int M) {
        // code here
        float mDegree = 6*M;
        float hDegree = 30*H + 0.5*M;
        
        int degree = abs(mDegree - hDegree);
        if(degree>180) {
            degree = 360-abs(hDegree - mDegree);
        }
        return degree;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}
// } Driver Code Ends