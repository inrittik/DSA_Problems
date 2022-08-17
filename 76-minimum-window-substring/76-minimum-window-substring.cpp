class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c:t) mp[c]++;
        
        int i = 0, j = 0, n = s.size();
        int len = INT_MAX;
        int cnt = t.size();
        int head = 0;
        while(j<n){
            if(mp[s[j++]]-->0) cnt--;
            while(cnt==0){
                if(j-i<len) len = j-(head=i);
                if(mp[s[i++]]++==0) cnt++;
            }
        }
        
        return len == INT_MAX?"":s.substr(head, len);
    }
};