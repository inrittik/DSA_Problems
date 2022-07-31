class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int maj = 0;
        
        for(int n: nums){
            mp[n]++;
            if(mp[n]>cnt){
                cnt = mp[n];
                maj = n;
            }
        }
        return maj;
    }
};