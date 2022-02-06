// all possible subsets of a string

#include<bits/stdc++.h>
using namespace std;

void printSubset(int n, int i, string S, string osf){
    if(i==n){
        cout <<'['<< osf <<']'<< endl;
    }
    else{
        printSubset(n, i+1, S, osf+(S[i])+',');
        printSubset(n, i + 1, S, osf);
    }
}

int main(){
    int n;
    string S;
    cin >> S;

    n = S.size();
    printSubset(n, 0, S, "");
    return 0;
}