// Leetcode - Minimum Deviation in an array

// Priority queue based
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue <int> pq;
        int mxi = INT_MIN, mni = INT_MAX, ans;
        for(int i = 0; i<n; ++i)
        {
            if((nums[i]%2) != 0) 
                nums[i] *= 2;  

            mxi = max(mxi,nums[i]);
            mni = min(mni,nums[i]);
        }
        ans = mxi - mni;
        for(int i=0; i<n; ++i){
            pq.push(nums[i]);
        }
        while(pq.top()%2==0){
            int x = pq.top();
            pq.pop();
            
            ans = min(ans, x-mni);
            x/=2;
            mni = min(mni, x);
            pq.push(x);
        }
        
        return min(ans, pq.top()-mni);
    }
};


// set based
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        int mxi = INT_MIN, mni = INT_MAX, ans;
        for(int i=0; i<n; ++i){
            if(nums[i]%2!=0) nums[i]*=2;
            
            mxi = max(mxi,nums[i]);
            mni = min(mni,nums[i]);
        }
        
        ans = mxi - mni;
        for(int i=0; i<n; ++i){
            s.insert(nums[i]);
        }
        
        while(*s.rbegin()%2==0){
            int x = *s.rbegin();
            s.erase(x);
            ans = min(ans, x-mni);
            x/=2;
            mni = min(mni, x);
            s.insert(x);
        }
        return min(ans,*s.rbegin()-mni);
    }
};