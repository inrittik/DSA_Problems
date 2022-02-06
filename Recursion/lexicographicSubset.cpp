#include<bits/stdc++.h>
using namespace std;

void subsetLexico(vector<int> A, int n, int ind, vector<int> v){
	if(ind==n){
		for(int i=0; i<v.size(); ++i) cout<<v[i];
		cout<<endl;
		return;
	}
	else{
		// subsetLexico(A, n, ind+1, v);
		v.push_back(A[ind]);
		for(int j=ind; j<n; ++j){
			subsetLexico(A, n, ind+1, v);
		}
	}
}

int main(){
    int n, x;
    cin>>n;
    vector<int> A, v;
    for(int i=0; i<n; ++i){
    	cin>>x;
    	A.push_back(x);
    }
    sort(A.begin(), A.end());
    subsetLexico(A, n, 0, v);
    return 0;
}