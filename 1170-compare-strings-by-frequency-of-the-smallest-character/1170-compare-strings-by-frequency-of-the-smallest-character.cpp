class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> f;
        for(string s:words){
            sort(s.begin(), s.end());
            int i = 1;
            while(i<s.size() && s[i]==s[i-1]) i++;
            f.push_back(i);
        }
        sort(f.begin(), f.end(), greater<int>());
        vector<int> ans;
        for(string s:queries){
            sort(s.begin(), s.end());
            int i = 1;
            while(i<s.size() && s[i]==s[i-1]) i++;
            int q = f.rend()-upper_bound(f.rbegin(), f.rend(), i);
            ans.push_back(q);
        }
        return ans;
    }
};