// leetcode - permutation sequence(optimised)

class Solution {
public:
    int fact(int n){
        if(n<2) return 1;
        return n*fact(n-1);
    }
public:
    void permutation(int n, int k, vector<char> &arr, string &perm){
        if(arr.size()==0){
            return;
        }
        else{
            int factorial = fact(n - 1);
            perm.push_back(arr[k/factorial]);
            arr.erase(arr.begin()+k/factorial);
            k=k%factorial;
            permutation(n-1, k, arr, perm);
        }
    }
public:
    string getPermutation(int n, int k) {
        string perm;
        vector<char> arr;
        for(int i=1; i<=n; ++i){
            arr.push_back(char(i)+'0');
        }
        permutation(n, --k, arr, perm);
        return perm;
    }
};