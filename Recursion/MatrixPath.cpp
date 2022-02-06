// all possible paths from (0,0) to (n-1, n-1) given a move can be either right, down or diagonal
#include<bits/stdc++.h>
using namespace std;

int totalPaths = 0;
void matrixPath(int i, int j, int n, int m, string osf){
    if(i==n-1 and j==m-1){
        cout << osf << endl;
        totalPaths++;
        return;
    }
    if(i>=n or j>=m){
        return;
    }
    else{
        matrixPath(i + 1, j, n, m, osf + 'D'); // down moves
        matrixPath(i, j+1, n, m, osf + 'R'); // right moves
        matrixPath(i + 1, j + 1, n, m, osf + 'X'); // diagonal moves
    }
}

int main(){
    matrixPath(0, 0, 3, 3, "");
    cout << totalPaths << endl;
    return 0;
}