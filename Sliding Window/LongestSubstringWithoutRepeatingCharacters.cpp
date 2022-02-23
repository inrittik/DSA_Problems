// Leetcode - Longest substring without repeating characters (3)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n=s.size();
        int i=0, j=0;
        int mx=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end() && mp[s[j]]>0){
                // mx=max(mx, j-i);
                mp[s[i]]--;
                i++;
            }
            else{
                mx=max(mx, j-i+1);
                if(mp.find(s[j])==mp.end() || mp[s[j]]==0) mp[s[j]]++;
                j++;
            }
        }
        return mx;
    }
};