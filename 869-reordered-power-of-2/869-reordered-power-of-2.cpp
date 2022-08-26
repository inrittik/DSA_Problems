class Solution {
public:
    int getNum(vector<int> num){
        int n = num.size();
        int val = 0;
        for(int i=n-1; i>=0; --i){
            val = num[i]+val*10;
        }
        // cout<<val<<endl;
        return val;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> num;
        if(n<=2) return true;
        if((n&(n-1))==0) return true;
        while(n){
            num.push_back(n%10);
            n /= 10;
        }
        sort(num.begin(), num.end());
        do{
            int val = getNum(num);
            if((val&(val-1))==0 && num[num.size()-1]!=0) return true;
        }while(next_permutation(num.begin(), num.end()));
        
        return false;
    }
};