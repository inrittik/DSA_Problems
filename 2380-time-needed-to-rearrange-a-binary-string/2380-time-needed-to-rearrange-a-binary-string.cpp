class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int lIn = 0;
        int n = s.size();
        int cnt = 0;
        while(true){
            int flag = false;
            string tmp = s;
            for(int i=1; i<n; ++i){
                if(s[i]=='1' && s[i-1]=='0'){
                    tmp[i] = '0';
                    tmp[i-1] = '1';
                    flag = true;
                }
            }
            if(!flag) break;
            cnt++;
            s = tmp;
        }
        return cnt;
    }
};