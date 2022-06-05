typedef pair<int, int> pp;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pp> pq;
        int n=arr.size();
        vector<int> ans;
        for(int i=0; i<n; ++i){
            pq.push({abs(arr[i]-x), arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};