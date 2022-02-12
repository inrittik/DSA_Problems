// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// Geeksforgeeks - Rat MAze Problem 1

class Solution{
    public:
    void getPath(vector<string> &ans, string osf, vector<vector<int>> &m, int n, int x, int y){
        if(x==n-1 && y==n-1){
            ans.push_back(osf);
            osf="";
            return;
        }
        else if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0){
            return;
        }
        else{
            m[x][y]=0;
            getPath(ans, osf+"L", m, n, x, y-1);
            getPath(ans, osf+"R", m, n, x, y+1);
            getPath(ans, osf+"U", m, n, x-1, y);
            getPath(ans, osf+"D", m, n, x+1, y);
            m[x][y]=1;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string osf="";
        if(m[0][0]==0) return {};
        if(m[n-1][n-1]==0) return {};
        getPath(ans, osf, m, n, 0, 0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
