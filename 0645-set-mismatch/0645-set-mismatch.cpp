class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);
        for(int i:nums) freq[i]++;
        vector<int> ans;
        for(int i=1; i<=n; ++i){
            if(freq[i]==2) ans.insert(ans.begin(), i);
            else if(freq[i]==0) ans.push_back(i);
        }
        return ans;
    }
};