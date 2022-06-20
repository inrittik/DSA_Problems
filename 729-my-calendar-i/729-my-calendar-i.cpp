class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> p = {start, end};
        
        auto itr = s.lower_bound(p);
        if( itr != s.end()   && !(itr -> first >= end) ||  
            itr != s.begin() && !(prev(itr) -> second <= start)) 
			    return false;
        s.insert(p);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */