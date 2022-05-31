class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int> prod(n+m);
        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                int d1 = num1[i]-'0';
                int d2 = num2[j]-'0';
                
                prod[i+j+1]+=d1*d2;
            }
        }
        
        int carry=0;
        for(int i=prod.size()-1; i>=0; --i){
            int temp = (prod[i]+carry)%10;
            carry = (prod[i]+carry)/10;
            prod[i]=temp;
        }
        
        string res;
        for(int i:prod){
            char c=i+'0';
            res.push_back(c);
        }
        while(res.length()!=0 && res[0]=='0') res.erase(res.begin());
        return res.length() == 0 ? "0" : res;
    }
};