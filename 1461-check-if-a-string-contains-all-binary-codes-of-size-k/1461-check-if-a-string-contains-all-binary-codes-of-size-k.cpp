class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string, int> mp;
        int n=s.size();
        int i=0, j=0;
        string str="";
        while(j<n){
            str.push_back(s[j]);
            if(j-i+1==k){
                mp[str]++;
                i++;
                str.erase(str.begin());
            }
            j++;
        }
        
        int num = pow(2, k);
        
        if(mp.size()<num) return false;
        else return true;
    }
};