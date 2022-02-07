// leetcode - permutation sequence (brute force) - not accepted

#include<bits/stdc++.h>
using namespace std;

void getPerms(vector<string> &perm, string osf, int ind, int n, set<int> s){
    if(ind>n){
        // cout << osf << endl;
        perm.push_back(osf);
        return;
    }
    for(int i=1; i<=n; ++i){
        if(s.count(i)==0){
            s.insert(i);
            osf.push_back(char(i)+'0');
            getPerms(perm, osf, ind + 1, n, s);
            osf.pop_back();
            s.erase(i);
        }
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<string> perm;
    set<int> s;
    getPerms(perm, "", 1, n, s);
    cout << perm[k - 1] << endl;
    return 0;
}