class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int n=prices.size();
       int num=1;
       while(!st.empty() && prices[st.top()]<=prices[n-1]){
           st.pop();
       }
       if(st.empty()){
           num+=n-1;
       }
       else num+=n-2-st.top();

       st.push(n-1);

       return num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */