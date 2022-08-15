class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        bool isPresent = false;
        for(string word:wordList){
            if(word==endWord){
                isPresent = true;
            }
            st.insert(word);
        }
        if(!isPresent) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            int lsize = q.size();
            depth++;
            while(lsize--){
                string curr = q.front();
                q.pop();
                
                for(int i=0; i<curr.size(); ++i){
                    string tmp = curr;
                    for(char j='a'; j<='z'; ++j){
                        if(tmp[i]!=j){
                            tmp[i] = j;
                            if(tmp.compare(endWord)==0) return depth+1;
                            if(st.find(tmp)!=st.end()){
                                q.push(tmp);
                                st.erase(tmp);
                            }
                        }
                    }
                }
            }  
        }
        
        return 0;
    }
};