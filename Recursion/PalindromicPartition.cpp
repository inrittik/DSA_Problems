// leetcode - palindrome partitioning

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
public:
    void palindrome(string s, int ind, vector<string> &osf, vector<vector<string>> &sstr){
        if(ind==s.size()){
            sstr.push_back(osf);
            return;
        }
        for(int i=ind; i<s.size(); ++i){
            if(isPalindrome(s, ind, i)){
                osf.push_back(s.substr(ind, i-ind+1));
                palindrome(s, i+1, osf, sstr);
                osf.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sstr;
        vector<string> osf;
        palindrome(s, 0, osf, sstr);
        return sstr;
    }
};