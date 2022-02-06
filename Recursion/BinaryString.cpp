// to print all binary strings of length n where no two consequtive bits are 1s

#include<bits/stdc++.h>
using namespace std;

void binaryString(int n, int prev, int i, string osf){
    if(i==n){
        cout << osf << endl;
    }
    else{
        if(prev==0){
            binaryString(n, 1, i+1, osf+'1');
        }
        binaryString(n, 0, i+1, osf+'0');
    }
}

int main(){
    int n;
    cin>>n;
    binaryString(n,0, 0, "");
    return 0;
}