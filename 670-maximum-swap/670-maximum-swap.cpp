class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int lg = 0;
        int sm = 0;
        int n = str.size();
        int mx = INT_MIN;
        for(int i=1; i<n; ++i){
            if(str[i]>=str[i-1] && str[i]>=mx){
                lg = i;
                mx = str[i];
            }
            if(str[i]<str[sm]){
                sm = i;
            }
        }
        int j = 0;
        while(j<n && str[j]>=str[lg]){
            j++;
        }
        string tmp = str;
        if(j<lg) swap(str[j], str[lg]);
        if(tmp==str){
            int j = n-1;
            while(j>=0 && str[j]<=str[sm]) j--;
            if(j>sm) swap(str[sm], str[j]);
        }
        return stoi(str);
    }
};