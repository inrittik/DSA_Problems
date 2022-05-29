// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long merge(long long arr[], long long lo, long long mid, long long hi, long long N){
    long long temp[N];
    
    long long i, j, k;
    long long inv_cnt=0;
    i=lo;
    j=mid;
    k=lo;
    
    while((i<=mid-1) && (j<=hi)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            
            inv_cnt+=(mid-i);
        }
    }
    
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    
    while(j<=hi){
        temp[k++]=arr[j++];
    }
    
    for(long long i=lo; i<=hi; ++i){
        arr[i]=temp[i];
    }
    
    return inv_cnt;
}
long long mergeSort(long long arr[], long long lo, long long hi, long long N){
    long long mid;
    long long inv_cnt=0;
    if(hi>lo){
        mid=lo+(hi-lo)/2;
        inv_cnt+=mergeSort(arr, lo, mid, N);
        inv_cnt+=mergeSort(arr, mid+1, hi, N);
        
        inv_cnt+=merge(arr, lo, mid+1, hi, N);
    }
    return inv_cnt;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N-1, N);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends