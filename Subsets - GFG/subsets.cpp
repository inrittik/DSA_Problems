// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        int N = A.size();
        vector<vector<int>> allSubsets;
        for(int mask = 0; mask<(1<<N); ++mask){
            vector<int> currSet;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)) currSet.push_back(A[i]);
            }
            allSubsets.push_back(currSet);
        }
        sort(allSubsets.begin(), allSubsets.end());
        return allSubsets;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends