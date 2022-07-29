class Solution {
public:
    void change(string& s){
        unordered_map<char, int> mp;
        
        char c = 'a';
        for(char ch:s){
            if(!mp.count(ch)) mp[ch] = c++;
        }
        for(auto& ch : s) ch = mp[ch];
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        change(pattern);
        
        for(string word:words){
            string temp = word;
            change(temp);
            if(temp==pattern) ans.push_back(word);
        }
        
        return ans;
    }
};