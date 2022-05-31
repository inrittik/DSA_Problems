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


/* The functions which 
builds the segment tree */
int len;
int *constructST(int arr[],int n)
{
  //Your code here
    int num = (ceil)(log2(n));
    len = (1<<num);
    int* tree = (int*)malloc(2*len * sizeof(int));
    for(int i=len; i<len+n; i++)
        tree[i] = arr[i-len];
    for(int i=len-1; i>=1; i--)
        tree[i] = min(tree[2*i], tree[2*i+1]);
    return tree;
}

int rangeQuery(int tree[], int a, int b, int lo, int hi, int pos){
    if(a<=lo && b>=hi){
        return tree[pos];
    }
    if(a>hi || b<lo){
        return INT_MAX;
    }
    
    int mid=(lo+hi)/2;
    
    return min(rangeQuery(tree, a, b, lo, mid, 2*pos),rangeQuery(tree, a, b, mid+1, hi, 2*pos+1));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return rangeQuery(st, a, b, 0, len-1, 1);
    
}