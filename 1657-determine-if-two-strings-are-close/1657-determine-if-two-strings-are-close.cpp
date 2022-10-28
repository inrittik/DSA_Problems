class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        if(word1==word2) return true;
        vector<int> f1(26), f2(26);
        for(char c:word1) f1[c-'a']++;
        for(char c:word2) f2[c-'a']++;
        for(int i=0; i<26; ++i){
            if(f1[i]>0 && f2[i]==0) return false;
        }
        unordered_map<int,int> mp;
        for(int i=0; i<26; ++i){
            mp[f1[i]]++;
        }
        for(int i=0; i<26; ++i){
            if(--mp[f2[i]]==0) mp.erase(f2[i]);
        }
        return mp.size()==0;
    }
};