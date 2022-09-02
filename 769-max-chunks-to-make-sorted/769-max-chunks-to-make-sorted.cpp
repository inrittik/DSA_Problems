class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int mx = 0;
        int i=0;
        while(i<n){
            mx = max(arr[i], mx);
            if(mx==i) cnt++;
            i++;
        }
        return cnt;
    }
};