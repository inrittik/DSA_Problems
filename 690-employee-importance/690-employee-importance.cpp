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
        for(auto it:employees){
            emp[it->id] = it;
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
                
                for(auto i:emp[emp_id]->subordinates){
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