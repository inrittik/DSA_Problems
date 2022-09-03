class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<pair<string,int>> q;
        for(int i=1; i<=9; ++i){
            q.push({to_string(i), i});
        }
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                int prev = f.second;
                string c = f.first;
                if(c.size()==n){
                    ans.push_back(stoi(c));
                    continue;
                }
                if(prev+k<=9){
                    c.push_back(prev+k+'0');
                    q.push({c, prev+k});
                    c.pop_back();
                }
                if(prev-k>=0 && k!=0){
                    c.push_back(prev-k+'0');
                    q.push({c, prev-k});
                    c.pop_back();
                }
            }
        }
        return ans;
    }
};