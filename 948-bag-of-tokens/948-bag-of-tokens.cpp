class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1;
        int cnt = 0, mx = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                mx = max(++cnt,mx);
            }
            else if(cnt==0) break;
            else{
                power+=tokens[j--];
                cnt--;
            }
        }
        return mx;
    }
};