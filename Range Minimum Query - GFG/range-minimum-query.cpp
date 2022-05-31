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


void build(int arr[] ,int *st, int ss, int se ,int si){
    if(ss == se){
        st[si] = arr[ss];
        return ;
    }
    int mid = ss + (se-ss)/2;
    build(arr,st,ss,mid,si*2+1);
    build(arr,st,mid+1,se,si*2+2);
    
    st[si] = min(st[si*2+1],st[si*2+2]);
    return;
}
int *constructST(int arr[],int n)
{
  int* tree = new int[4*n+1];
  build(arr, tree, 0, n-1, 0);
  
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