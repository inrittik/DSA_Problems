class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> dead;
        for(string s:deadends) dead[s]++;
        
        string str = "0000";
        if(dead[str]) return -1;
        queue<string> q;
        unordered_map<string,int> vis;
        q.push(str);
        vis[str]++;
        int ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr==target) return ans-1;
                
                for(int i=0; i<4; ++i){
                    string tmp = curr;
                    int t = tmp[i] - '0';
                    tmp[i] = (t+1)%10 + '0';
                    if(!vis[tmp] && !dead[tmp]){
                        q.push(tmp);
                        vis[tmp]++;
                    }
                    tmp = curr;
                    tmp[i] = (t-1+10)%10 + '0';
                    if(!vis[tmp] && !dead[tmp]){
                        q.push(tmp);
                        vis[tmp]++;
                    }
                }
            }
        }
        
        return -1;
    }
};