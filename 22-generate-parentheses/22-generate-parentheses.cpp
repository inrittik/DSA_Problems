class Solution {
public:
    void helper(vector<string>& ans, int n, int op, int cl, string& osf){
        if(op>n) return;
        
        if(cl>op) return;
        
        if(op==cl && op==n){
            ans.push_back(osf);
            return;
        }
        
        osf += "(";
        helper(ans, n, op+1, cl, osf);
        osf.pop_back();
        osf += ")";
        helper(ans, n, op, cl+1, osf);
        osf.pop_back();
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string osf = "";
        helper(ans, n, 0, 0, osf);
        return ans;
    }
};