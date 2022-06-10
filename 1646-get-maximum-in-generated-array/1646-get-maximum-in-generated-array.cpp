class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> arr(n+1, 0);
        if(n<=1) return n;
        arr[0] = 1, arr[1] = 1;
        int mx = 1;
        for(int i=2; i<=n; ++i){
            if(i%2==0){
                arr[i] = arr[i/2];
            }
            else{
                arr[i] = arr[i/2]+arr[i/2+1];
            }
            mx = max(mx, arr[i]);
        }
        return mx;
    }
};