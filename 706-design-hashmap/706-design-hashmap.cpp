class MyHashMap {
public:
    vector<int> mp;
    int sz;
    MyHashMap() {
        sz = 0;
    }
    
    void put(int key, int value) {
        if(sz<=key){
            mp.resize(key+1,-1);
            mp[key] = value;
            sz = key+1;
        }
        else{
            mp[key] = value;
        }
    }
    
    int get(int key) {
        return (sz<=key || mp[key]==-1)? -1:mp[key];
    }
    
    void remove(int key) {
        if(sz>key) mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */