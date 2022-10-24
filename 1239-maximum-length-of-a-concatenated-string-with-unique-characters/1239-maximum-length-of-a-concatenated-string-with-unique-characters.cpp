class Solution {
public:
    int mx = 32;
    int helper(vector<string>& arr, int mask, int i){
        if(i==arr.size()) return 0;
        int n = arr[i].size();
        int m = mask;
        for(int j=0; j<n; ++j){
            int num = arr[i][j] - 'a';
            if(mask&(1<<num)) return helper(arr, m, i+1);
            else mask |= (1<<num);
        }
        int sec = arr[i].size()+helper(arr, mask, i+1);
        return max(helper(arr, m, i+1), sec);
    }
    int maxLength(vector<string>& arr) {
        int mask = 0;
        return helper(arr, mask, 0);
    }
};