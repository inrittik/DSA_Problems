class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        if(n==1) {
            if(intervals[0][1]<newInterval[0]){
                ans.push_back(intervals[0]);
                ans.push_back(newInterval);
                return ans;
            }
            else if(intervals[0][0]>newInterval[1]){
                ans.push_back(newInterval);
                ans.push_back(intervals[0]);
                return ans;
            }
        }
        
        if(newInterval[1]<intervals[0][0]) ans.push_back(newInterval);
        
        for(int i=0; i<n;){
            if(intervals[i][0]>newInterval[1] || intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
                if(i<n && intervals[i][0]>newInterval[1] && intervals[i-1][0]<newInterval[1]) ans.push_back(newInterval);
                continue;
            }
            while((i<n && intervals[i][0]<=newInterval[0] && intervals[i][1]>=newInterval[0]) || (i<n && intervals[i][0]>=newInterval[0] && intervals[i][0]<=newInterval[1])){
                newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
                i++;
            }
            ans.push_back(newInterval);
        }
        
        if(intervals[n-1][1]<newInterval[0]){
            ans.push_back(newInterval);
        }
        return ans;
    }
};