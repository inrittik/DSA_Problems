class SmallestInfiniteSet {
public:
    set<int, greater<int>> popped;
    set<int> added;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(popped.empty()){
            popped.insert(1);
            return 1;
        }
        else{
            int n = *popped.begin();
            for(int i=1; i<n; ++i){
                if(popped.find(i)==popped.end()) {
                    popped.insert(i);
                    return i;
                }
            }
            popped.insert(n+1);
            return n+1;
        }
    }
    
    void addBack(int num) {
        popped.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */