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
  int *st = new int[4*n + 1];
  build(arr,st,0,n-1,0);
  return st;
}

int getmin(int *st , int ss ,int se , int qs , int qe ,int si) {
    if(se<qs || ss>qe)    {
        return INT_MAX;
    }
    if(ss>=qs && qe>=se){
        return st[si];
    }
    
    int mid = ss + (se-ss)/2;
    return min(getmin(st,ss,mid,qs,qe,2*si+1),getmin(st,mid+1,se,qs,qe,2*si+2));
}

int RMQ(int st[] , int n, int a, int b)
{
    return getmin(st,0,n-1,a,b,0);
}