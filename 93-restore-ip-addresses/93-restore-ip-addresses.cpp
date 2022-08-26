class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if(n>12) return ans;
        for(int i=1; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                for(int k=j+1; k<n; ++k){
                    string str1 = s.substr(0, i);
                    string str2 = s.substr(i, j-i);
                    string str3 = s.substr(j, k-j);
                    string str4 = s.substr(k, n-k);
                    
                    long long num1 = stoll(str1);
                    long long num2 = stoll(str2);
                    long long num3 = stoll(str3);
                    long long num4 = stoll(str4);
                    
                    if(str1!=to_string(num1)) continue;
                    if(str2!=to_string(num2)) continue;
                    if(str3!=to_string(num3)) continue;
                    if(str4!=to_string(num4)) continue;
                    
                    if(num1>255 || num2>255 || num3>255 || num4>255) continue;
                    ans.push_back(str1+"."+str2+"."+str3+"."+str4);
                    // cout<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<endl; 
                }
            }
        }
        return ans;
    }
};