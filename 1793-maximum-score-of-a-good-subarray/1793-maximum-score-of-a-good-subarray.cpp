class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> right(n);
        vector<int> left(n);
        
        stack<int> nsr;
        stack<int> nsl;
        
        for(int i=0; i<n; ++i){
            while(!nsl.empty() && nums[nsl.top()]>=nums[i]){
                nsl.pop();
            }
            if(nsl.empty()){
                left[i]=0;
            }
            else{
                left[i]=nsl.top()+1;
            }
            
            nsl.push(i);
        }
        
        for(int i=n-1; i>=0; --i){
            while(!nsr.empty() && nums[nsr.top()]>=nums[i]){
                nsr.pop();
            }
            if(nsr.empty()){
                right[i]=n-1;
            }
            else{
                right[i]=nsr.top()-1;
            }
            
            nsr.push(i);
        }
        
        int mxArea=nums[k];
        for(int i=0; i<n; ++i){
            if(left[i]<=k && right[i]>=k){
                mxArea = max(mxArea, (right[i]-left[i]+1)*nums[i]);
            }
        }
        
        return mxArea;
    }
};