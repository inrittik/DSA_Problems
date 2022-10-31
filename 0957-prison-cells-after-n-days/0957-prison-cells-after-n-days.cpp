class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while(n--){
            for(int j=1; j<7; ++j){
                if(cells[j-1]==cells[j+1]) tmp[j]=1;
                else tmp[j]=0;
            }
            if (seen.size() && seen.front() == tmp) return seen[n % seen.size()]; 
            else seen.push_back(tmp);
            cells = tmp;
        }
        return cells;
    }
};