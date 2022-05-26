class Solution {
public:
    void formParenthesis(vector<string> &comb, string &osf, int op, int cl, int size){
        int s=osf.size();
        if(2*size==s){
            comb.push_back(osf);
            return;
        }
        if(op<size){
            formParenthesis(comb, osf+="(", op+1, cl, size);
            osf.pop_back();
        }
        if(cl<op){
            formParenthesis(comb, osf+=")", op, cl+1, size);
            osf.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> comb;
        string osf="";
        formParenthesis(comb, osf, 0, 0, n);
        return comb;
    }
};