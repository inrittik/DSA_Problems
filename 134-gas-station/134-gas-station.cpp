class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int ind = 0;
        int mn = 0;
        int curr = 0;
        for(int i=0; i<n; ++i){
            gas[i] -= cost[i];
            sum += gas[i];
            if(curr<0){
                ind = i;
                curr = 0;
            }
            curr += gas[i];
        }
        if(sum>=0) return ind;
        else return -1;
    }
};