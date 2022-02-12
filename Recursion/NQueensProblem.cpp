// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// GeeksforGeeks - N Queens Problem

class Solution{
public:
    bool isSafe1(int row, int col, vector<vector<int>> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 1) return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 1) return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 1) return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, vector<int> &osf) {
        if(col == n) {
            ans.push_back(osf); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 1; 
                osf.push_back(row+1);
                solve(col+1, board, ans, n, osf); 
                board[row][col] = 0; 
                osf.pop_back();
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans; 
        vector<vector<int>> board;
        vector<int> osf;
        vector<int> s;
        for(int i = 0;i<n;i++) {
            s.push_back(0);
        }
        for(int i = 0;i<n;i++) {
            board.push_back(s);
        } 
        solve(0,board, ans, n, osf); 
        return ans; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends