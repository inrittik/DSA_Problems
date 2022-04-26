class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        visited.insert(0);
        
        stack<int> to_visit;
        to_visit.push(0);
        
        while(!to_visit.empty()){
            int cur = to_visit.top();
            to_visit.pop();
            
            for(int j:rooms[cur]){
                if(visited.count(j)==0){
                    to_visit.push(j);
                    visited.insert(j);
                }
            }
        }
        
        return rooms.size() == visited.size();
    }
};