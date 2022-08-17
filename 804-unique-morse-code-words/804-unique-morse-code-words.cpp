class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string word:words){
            string tmp;
            for(int i=0; i<word.size(); ++i){
                tmp+=code[word[i]-'a'];
            }
            s.insert(tmp);
        }
        
        return s.size();
    }
};