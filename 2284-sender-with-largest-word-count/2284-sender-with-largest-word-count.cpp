class Solution {
public:
    int numWords(string s){
        int cnt=0;
        for(char c:s){
            if(c==' ') cnt++;
        }
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        unordered_map<string, int> mp;
        for(int i=0; i<n; ++i){
            int cnt = numWords(messages[i]);
            mp[senders[i]]+=cnt;
        }
        int mx=INT_MIN;
        string ans=senders[0];
        for(auto it:mp){
            if(it.second>mx){
                mx=it.second;
                ans=it.first;
            }
            else if(it.second==mx){
                ans=max(ans, it.first);
            }
        }
        return ans;
    }
};