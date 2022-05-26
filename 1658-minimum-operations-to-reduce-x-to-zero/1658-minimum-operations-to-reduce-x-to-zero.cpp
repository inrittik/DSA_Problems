class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int, int> pref;
        unordered_map<int, int> suff;
        int sum=0;
        for(int i=0; i<n; ++i){
            sum+=nums[i];
            pref[sum]=i;
        }
        if(sum<x) return -1;
        sum=0;
        for(int i=n-1; i>=0; --i){
            sum+=nums[i];
            suff[sum]=i;
        }
        int numOfOp=INT_MAX;
        for(auto it:pref){
            int op=0;
            if(suff.find(x-it.first)!=suff.end()){
                op=it.second+1;
                op+=n-suff.find(x-it.first)->second;
                numOfOp=min(op, numOfOp);
            }
            if(x-it.first==0){
                op=it.second+1;
                numOfOp=min(op, numOfOp);
            }
        }
        for(auto it:suff){
            int op=0;
            if(pref.find(x-it.first)!=pref.end()){
                op=n-it.second;
                op+=pref.find(x-it.first)->second+1;
                numOfOp=min(op, numOfOp);
            }
            if(x-it.first==0){
                op=n-it.second;
                numOfOp=min(op, numOfOp);
            }
        }
        if(numOfOp==INT_MAX) return -1;
        else return numOfOp;
    }
};