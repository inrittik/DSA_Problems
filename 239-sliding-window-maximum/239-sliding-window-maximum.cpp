class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> mx;
        int i=0, j=0;
        int n = nums.size();
        if(k>nums.size()){
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }
        while(j<n){
            if(nums[j]>mx.front()){
                mx.clear();
                mx.push_front(nums[j]);
            }
            else if(nums[j]<=mx.front()){
                while(nums[j]>mx.back() && mx.size()!=0){
                    mx.pop_back();
                }
                mx.push_back(nums[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(mx.front());
                if(nums[i]==mx.front()){
                    mx.pop_front();
                }
                i++, j++;
            }
        }
        return ans;
    }
};