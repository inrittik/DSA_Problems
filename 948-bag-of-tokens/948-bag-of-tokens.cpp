class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1;
        int cnt = 0, mx = 0;
        while(i<=j && cnt>=0){
            if(power-tokens[i]>=0){
                power-=tokens[i];
                cnt++;
                mx = max(mx, cnt);
                i++;
            }
            else{
                power+=tokens[j];
                cnt--;
                j--;
            }
        }
        return mx;
    }
};