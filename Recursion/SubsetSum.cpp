// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

 // prints the sum of all possible subsets of given array
class Solution
{
public:
    void getSum(vector<int> &sums, int N, int ind, int sum, vector<int> arr){
        if(ind==N){
            sums.push_back(sum);
            return;
        }
        else{
            getSum(sums, N, ind+1, sum, arr);
            sum+= arr[ind];
            getSum(sums, N, ind+1, sum, arr);
        }
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sums;
        sort(arr.begin(), arr.end(), greater<int>());
        getSum(sums, N, 0, 0, arr);
        return sums;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends