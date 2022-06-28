class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        int n = s.size();
        for(int i=0; i<n; ++i){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(), freq.end());
        int cnt = 0;
        for(int i=1; i<26; ++i){
            if(freq[i]==freq[i-1] && freq[i]>0){
                cnt++;
                freq[i-1]--;
                i=1;
                sort(freq.begin(), freq.end());
            }
        }
        return cnt;
    }
};