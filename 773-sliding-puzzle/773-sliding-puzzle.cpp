class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string res = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        string str = "";
        int ind;
        for(int i=0; i<2; ++i){
            for(int j=0; j<3; ++j){
                str+=(board[i][j]+'0');
                if(board[i][j]==0){
                    ind = i*3+j;
                }
            }
        }
        if(str==res) return 0;
        queue<pair<string, int>> q;
        q.push({str,ind});
        unordered_map<string,int> mp;
        mp[str]++;
        int depth = 0;
        while(!q.empty()){
            int sz = q.size();
            depth++;
            while(sz--){
                string curr = q.front().first;
                int ind = q.front().second;
                q.pop();

                for(int it:moves[ind]){
                    string tmp = curr;
                    swap(tmp[ind], tmp[it]);
                    if(!mp.count(tmp)){
                        q.push({tmp,it});
                        if(tmp==res) return depth;
                        mp[tmp]++;
                    }
                }
            }
        }
        return -1;
    }
};