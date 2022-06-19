struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* getRef(char c){
        return links[c-'a'];
    }
    void markEnd(){
        flag = true;
    }
};

class MagicDictionary {
    Node* root;
public:
    MagicDictionary() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; ++i){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->getRef(word[i]);
        }
        
        node->markEnd();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s:dictionary){
            insert(s);
        }
    }
    
    bool searchTrie(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; ++i){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getRef(word[i]);
        }
        return node->flag;
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        for(int i=0; i<n; ++i){
            string s = searchWord.substr(0);
            char originalchar = s[i];
            for(char j='a'; j<='z'; ++j){
                s[i]=originalchar;
                if(s[i]!=j){
                    s[i]=j;
                    if(searchTrie(s)) return true;   
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */