class StockSpanner {
public:
    stack<pair<int, int>> st;
    int n = 0;
    StockSpanner() {
    }
    
    int next(int price) {
       n++;
       int num=0;
       while(!st.empty() && st.top().first<=price){
           st.pop();
       }
       if(st.empty()){
           num+=n;
       }
       else num+=n-1-st.top().second;

       st.push({price, n-1});

       return num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */