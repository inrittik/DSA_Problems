class Solution {
public:
    string countAndSay(int n) {
        vector<string> str(n+1, "");
        str[1] = "1";
        for(int i=2; i<=n; ++i){
            string prev = str[i-1];
            int sz = prev.size();
            int j=0;
            while(j<sz){
                int cnt = 1;
                j++;
                while(j<sz && prev[j]==prev[j-1]){
                    cnt++;
                    j++;
                }
                str[i]+=to_string(cnt)+prev[j-1];
            }
        }
        return str[n];
    }
};