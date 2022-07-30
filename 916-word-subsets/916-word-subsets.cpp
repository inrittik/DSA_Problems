class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        
        vector<int> v(26);
        for(string word:words2){
            vector<int> temp(26);
            for(char c:word){
                temp[c-'a']++;
            }
            
            for(int i=0; i<26; ++i){
                v[i] = max(v[i], temp[i]);
            }
        }
        
        for(string word:words1){
            vector<int> temp(26);
            for(char c:word) temp[c-'a']++;
            
            bool flag = true;
            for(int i=0; i<26; ++i){
                if(v[i]>temp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(word);
        }
        
        return ans;
    }
};