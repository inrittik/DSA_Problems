// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


void constructTree(int arr[], int* tree, int lo, int hi, int pos){
    if(lo==hi){
        tree[pos]=arr[lo];
        return;
    }
    int mid=lo+(hi-lo)/2;
    
    constructTree(arr, tree, lo, mid, 2*pos+1);
    constructTree(arr, tree, mid+1, hi, 2*pos+2);
    
    tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
}
int *constructST(int arr[],int n)
{
  int* tree = new int[4*n+1];
  constructTree(arr, tree, 0, n-1, 0);
  
  return tree;
}

int rangeQuery(int* tree, int a, int b, int lo, int hi, int pos){
    if(hi<a || lo>b){
        return INT_MAX;
    }
    if(a<=lo && b>=hi){
        return tree[pos];
    }
    
    int mid=lo+(hi-lo)/2;
    
    return min(rangeQuery(tree, a, b, lo, mid, 2*pos+1),rangeQuery(tree, a, b, mid+1, hi, 2*pos+2));
}

int RMQ(int st[] , int n, int a, int b)
{
    return rangeQuery(st, a, b, 0, n-1, 0);
    
}