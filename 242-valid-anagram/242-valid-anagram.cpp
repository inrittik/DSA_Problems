class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.size()!=t.size()) return false;
        for(char c:s) mp[c]++;
        
        for(char c:t){
            if(mp.size()==0) return false;
            
            if(!mp.count(c)) return false;
            else{
                mp[c]--;
                if(mp[c]==0) mp.erase(c);
            }
        }
        
        return true;
    }
};