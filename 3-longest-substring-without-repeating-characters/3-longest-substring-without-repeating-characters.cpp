class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0, j=0;
        unordered_map<char, int> mp;
        int len=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.find(s[j])!=mp.end() && mp[s[j]]==2){
                while(mp[s[j]]!=1){
                    mp[s[i]]--;
                    i++;
                }
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};