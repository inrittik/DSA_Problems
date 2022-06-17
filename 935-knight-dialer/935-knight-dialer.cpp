class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> path(10);
        path[0]={4,6}, path[1]={6,8}, path[2]={7,9}, path[3]={4,8}, path[4]={0,3,9}, path[5]={}, path[6]={0,1,7}, path[7]={2,6}, path[8]={1,3}, path[9]={2,4};
        
        vector<long long> prev(10,1), cur(10,0);

        int mod=1e9+7;
        for(int i=2; i<=n; ++i){
            for(int j=0; j<10; ++j){
                cur[j]=0;
                for(int a:path[j]){
                    cur[j]=cur[j]+prev[a];
                }
                cur[j]%=mod;
            }
            prev=cur;
        }
        
        long long sum = 0;
        for(int i=0; i<10; ++i){
            sum=sum+prev[i]%mod;
        }
        return sum%mod;
    }
};