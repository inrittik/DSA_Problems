class Solution {
public:
    unordered_set<string> mp;
    bool converse(string t){
        int n=t.length();
        for (int i=0;i<n;i++){
            string temp="";
            for (int j=0;j<n;j++){
                if (j==i)
                    continue;
                temp.push_back(t[j]);
            }
            if (mp.find(temp)!=mp.end())
                return true;
        }
        return false;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int cnt = 0;
        for(string s:startWords){
            sort(s.begin(), s.end());
            mp.insert(s);
        }
        for(string t:targetWords){
            sort(t.begin(), t.end());
            if(converse(t)) {
                cnt++;
            }
        }
        return cnt;
    }
};