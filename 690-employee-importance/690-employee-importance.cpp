/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp;
        unordered_map<int, vector<int>> rel;
        for(auto it:employees){
            emp[it->id] = it;
            vector<int> tmp = vector(it->subordinates.begin(), it->subordinates.end());
            rel[it->id] = tmp;
        }
        
        queue<int> q;
        q.push(id);
        int imp = 0;
        unordered_map<int, int> vis;
        vis[id]++;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int emp_id = q.front(); q.pop();
                imp+=emp[emp_id]->importance;
                
                for(auto i:rel[emp_id]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]++;
                    }
                }
            }
        }
        return imp;
    }
};