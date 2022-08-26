class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        set<string> res;
        
        int i = 0, j = 0;
        string str = "";
        while(j<n){
            str += s[j];
            if(j-i+1 == 10){
                if(mp.count(str)) {
                    res.insert(str);
                }
                mp[str]++;
                str.erase(0,1);
                i++;
            }
            j++;
        }
        return vector<string>(res.begin(), res.end());
    }
};