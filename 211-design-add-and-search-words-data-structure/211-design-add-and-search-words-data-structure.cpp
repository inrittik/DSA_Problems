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

class WordDictionary {
    Node* root;
    
    // recursive search function
    bool search(const char* word, Node* root){
        for(int i=0; word[i] && root; ++i){
            if(word[i]=='.'){
                Node* tmp = root;
                for (int j = 0; j < 26; j++) {
                    root = tmp -> getRef(j+'a');
                    if (search(word + i + 1, root)) {
                        return true;
                    }
                }
            }
            else{
                if(!root->containsKey(word[i])){
                    return false;
                }
                root = root->getRef(word[i]);
            }
        }
        return root && root->flag;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */