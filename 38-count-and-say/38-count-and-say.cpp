class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for(int i=2; i<=n; ++i){
            string prev = curr;
            curr = "";
            int sz = prev.size();
            int j=0;
            while(j<sz){
                int cnt = 1;
                j++;
                while(j<sz && prev[j]==prev[j-1]){
                    cnt++;
                    j++;
                }
                curr+=to_string(cnt)+prev[j-1];
            }
        }
        return curr;
    }
};