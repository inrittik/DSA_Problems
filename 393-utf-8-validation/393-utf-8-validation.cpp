class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0; i<data.size(); ++i){
            string str = bitset<8>(data[i]).to_string();
            int bytes = 0;
            if(str[0]=='0') bytes = 1;
            if(str[0]=='1' && str[1]=='1' && str[2]=='0') bytes = 2;
            if(str[0]=='1' && str[1]=='1' && str[2]=='1' && str[3]=='0') bytes = 3;
            if(str[0]=='1' && str[1]=='1' && str[2]=='1' && str[3]=='1' && str[4]=='0') bytes=4;
            if(data.size()-i<bytes) return false;
            if(bytes==0) return false;
            if(bytes==1) continue;
            int j = i+1;
            while(j<data.size() && j<i+bytes){
                string str = bitset<8>(data[j]).to_string();
                if(str[0]=='1' && str[1]=='0') {
                    j++;
                }
                else return false;
            }
            i+=bytes-1;
        }
        return true;
    }
};