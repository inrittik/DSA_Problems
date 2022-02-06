// all possible combinations of linear jumps to reach a destination given each jump corresponds to a length of 1-6

#include<bits/stdc++.h>
using namespace std;

int totalPaths = 0;
void linearJumps(int i, int n, string osf){
    if(i==n-1){
        cout << osf << endl;
        totalPaths++;
        return;
    }
    if(i>=n){
        return;
    }
    else{
        linearJumps(i + 1, n, osf + '1');
        linearJumps(i + 2, n, osf + '2');
        linearJumps(i + 3, n, osf + '3');
        linearJumps(i + 4, n, osf + '4');
        linearJumps(i + 5, n, osf + '5');
        linearJumps(i + 6, n, osf + '6');
    }
}

int main(){
    linearJumps(0, 4, "");
    cout << totalPaths << endl;
    return 0;
}