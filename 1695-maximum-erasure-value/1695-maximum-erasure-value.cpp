class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int score = 0;
        int mxScore = 0;
        int n=nums.size();
        unordered_map<int, int> mp;
        int i=0, j=0;
        while(j<n){
            mp[nums[j]]++;
            score+=nums[j];
            if(mp[nums[j]]>1){
                while(mp[nums[j]]>1){
                    mp[nums[i]]--;
                    score-=nums[i];
                    i++;
                }
            }
            mxScore=max(score, mxScore);
            j++;
        }
        return mxScore;
    }
};