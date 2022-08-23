class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* next = NULL;
            Node* prev = NULL;
            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int sz;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        sz = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node){
        Node* tmp = head->next;
        node->next = tmp;
        tmp->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    void deleteNode(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* res = mp[key];
            int val = res->val;
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        }
        if(mp.size() == sz){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */