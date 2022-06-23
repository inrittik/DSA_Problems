class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> pq;
        int n = courses.size();
        int totalTime = 0;
        for(int i=0; i<n; ++i){
            int dur = courses[i][0];
            int end = courses[i][1];
            if(totalTime+dur<=end){
                totalTime+=dur;
                pq.push(dur);
            }
            else if(!pq.empty() && pq.top()>dur){
                totalTime+=dur;
                totalTime-=pq.top();
                pq.pop();
                pq.push(dur);
            }
            
        }
        return pq.size();
    }
};