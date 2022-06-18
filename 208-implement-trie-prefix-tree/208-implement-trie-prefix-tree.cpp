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

class Trie {
    Node* root;
public:
    Trie() {
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
    
    bool search(string word) {
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
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();
        for(int i=0; i<n; ++i){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getRef(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */