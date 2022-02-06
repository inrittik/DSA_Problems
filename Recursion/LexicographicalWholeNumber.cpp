// lexicographically prints all decimal numbers less than or equal to n
#include<bits/stdc++.h>
using namespace std;

void lexicoWhole(int n, int i){
    if(i>n)
        return;
    cout << i << endl;
    for (int j = (i == 0) ? 1 : 0; j <= 9; ++j){
        lexicoWhole(n, 10 * i + j);
    }
}

int main(){
    int n;
    cin>>n;
    lexicoWhole(n, 0);
    return 0;
}