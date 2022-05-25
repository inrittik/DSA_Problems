class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return strs[0];
        int k=0;
        string res;
        while(true){
            for(int i=1; i<n; ++i){
                if(k==strs[i-1].size()) return res;
                if(strs[i][k]!=strs[i-1][k]){
                    return res;
                }
            }
            res.push_back(strs[0][k++]);
        }
        return res;
    }
};