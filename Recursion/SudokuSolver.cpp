// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

// Geeksforgeeks - Sudoku Solver

class Solution 
{
    public:
    // checks if position is empty ans safe
    bool isSafe(int grid[N][N], int row, int col, int key){
        for(int i=0; i<N; ++i){
            if(grid[row][i]==key) return false;
        }
        for(int i=0; i<N; ++i){
            if(grid[i][col]==key) return false;
        }
        row/=3;
        col/=3;
        row*=3;
        col*=3;
        for(int i=row; i<row+3; ++i){
            for(int j=col; j<col+3; ++j){
                if(grid[i][j]==key) return false;
            }
        }
        return true;
    }
    public:
    // checks if a solution is possible and builds the solution
    bool isPossible(int grid[N][N], int row, int col){
        if(row==N){
            return true;
        }
        else if(col==N){
            isPossible(grid, row+1, 0);
        }
        else if(grid[row][col]!=0){
            isPossible(grid, row, col+1);
        }
        else{
            for(int i=1; i<=9; ++i){
                if(isSafe(grid, row, col, i)){
                    grid[row][col]=i;
                    if(isPossible(grid, row, col+1)){
                        return true;
                    }
                    grid[row][col]=0;
                }
            }
            return false;
        }
    }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return isPossible(grid, 0, 0);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends