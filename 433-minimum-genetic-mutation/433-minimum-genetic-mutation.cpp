class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        char choices[4] = {'A', 'C', 'G', 'T'};
        bool isPresent = false;
        for(string str:bank){
            if(str == end) isPresent = true;
            s.insert(str);
        }
        if(!isPresent) return -1;
        
        queue<string> q;
        q.push(start);
        int depth = 0;
        
        while(!q.empty()){
            int sz = q.size();
            depth++;
            while(sz--){
                string curr = q.front(); q.pop();
                
                for(int i=0; i<curr.size(); ++i){
                    string tmp = curr;
                    for(int j = 0; j<4; ++j){
                        if(tmp[i]!=choices[j]){
                            tmp[i] = choices[j];
                            if(tmp.compare(end)==0) return depth;
                            if(s.find(tmp)!=s.end()){
                                q.push(tmp);
                                s.erase(tmp);
                            }
                        }
                        
                    }
                }
            }
        }
        return -1;
    }
};