class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char c:magazine){
            mp[c]++;
        }
        
        for(char c:ransomNote){
            if(!mp.count(c)) return false;
            else{
                mp[c]--;
                if(mp[c]==0) mp.erase(c);
            }
        }
        
        return true;
    }
};