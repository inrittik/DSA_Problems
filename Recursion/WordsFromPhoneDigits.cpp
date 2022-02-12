// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Geeksforgeeks - Possible Words from phone digits

class Solution
{
    public:
    void getWords(int arr[], int N, vector<string> &ans, vector<string> &letters, string &osf, int ind){
        if(N==0){
            ans.push_back(osf);
        }
        else{
            int i = arr[ind]-2;
            for(auto it: letters[i]){
                osf.push_back(it);
                getWords(arr, N-1, ans, letters, osf, ind+1);
                osf.pop_back();
            }
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        vector<string> letters;
        string osf;
        letters.push_back("abc");
        letters.push_back("def");
        letters.push_back("ghi");
        letters.push_back("jkl");
        letters.push_back("mno");
        letters.push_back("pqrs");
        letters.push_back("tuv");
        letters.push_back("wxyz");
        getWords(a, N, ans, letters, osf, 0);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends