class Solution {
public:
    string stringify(int num){
        string res = to_string(num);
        sort(res.begin(), res.end());
        return res;
    }
    bool reorderedPowerOf2(int n) {
        string str = stringify(n);
        for(int i=0; i<32; ++i) if(str == stringify(1<<i)) return true;
        return false;
    }
};