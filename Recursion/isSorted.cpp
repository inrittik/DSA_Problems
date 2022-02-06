// recursive code to check whether an array is sorted
#include<bits/stdc++.h>
using namespace std;

void isSorted(int arr[], int n, int i, int prev){
    if(i==n){
        cout << "YES" << endl;
        return;
    }
    else{
        if(arr[i]<arr[prev]){
            cout << "NO" << endl;
            return;
        }
        else{
            isSorted(arr, n, i + 1, i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    isSorted(arr, n, 1, 0);
    return 0;
}