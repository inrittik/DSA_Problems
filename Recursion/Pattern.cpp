#include<bits/stdc++.h>
using namespace std;

void pattern1(int n, int col){
    if(n==0){
        return;
    }
    if(col<n){
        cout << "* ";
        pattern1(n, col + 1);
    }
    else{
        cout << endl;
        pattern1(n - 1, 0);
    }
}

void pattern2(int n, int col){
    if(n==0){
        return;
    }
    if(col<n){
        pattern2(n, col + 1);
        cout << "* ";
    }
    else{
        pattern2(n - 1, 0);
        cout << endl;
        // for (int i = 0; i < n; ++i){
        //     cout << "* ";
        // }
    }
}

int main(){
    // pattern1(5, 0);
    pattern2(5, 0);
    return 0;
}