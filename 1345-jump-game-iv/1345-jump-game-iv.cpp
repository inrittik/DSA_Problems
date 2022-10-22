class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        set<int> vis;
        int n = arr.size();
        if(n==1) return 0;
        for(int i=0; i<n; ++i){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int l = 0;
        while(!q.empty()){
            int sz = q.size();
            l++;
            while(sz--){
                int i = q.front();
                vis.insert(i);
                q.pop();
                if(i==n-1) return l-1;
                for(int j:mp[arr[i]]){
                    if(i==j || vis.count(j)) continue;
                    q.push(j);
                }
                if(i-1>=0 && vis.find(i-1)==vis.end()) q.push(i-1);
                if(i+1<n && vis.find(i+1)==vis.end()) q.push(i+1);
                mp[arr[i]].clear();
            }
        }
        return 0;
    }
};