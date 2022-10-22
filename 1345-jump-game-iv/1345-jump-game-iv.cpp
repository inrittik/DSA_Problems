class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> vis;
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
            while(sz--){
                int i = q.front();
                q.pop();
                if(i==n-1) return l;
                if(i-1>=0) mp[arr[i]].push_back(i-1);
                if(i+1<n) mp[arr[i]].push_back(i+1);
                for(int j:mp[arr[i]]){
                    if(i==j || vis.count(j)) continue;
                    q.push(j);
                    vis[j]++;
                }
                mp[arr[i]].clear();
            }
            l++;
        }
        return 0;
    }
};