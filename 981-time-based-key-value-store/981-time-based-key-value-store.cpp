class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) && mp[key].count(timestamp)) return mp[key][timestamp];
        else if(mp.count(key)){
            auto it = mp[key].lower_bound(timestamp);
            if(it==mp[key].begin()) return "";
            if(it->first==timestamp) return it->second;
            else{
                --it;
                return it->second;
            }
        }
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */