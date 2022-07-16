class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(int n:s){
            if(s.count(n-1)) continue;
            int j = 1;
            while(s.count(n + j)) j++;
		    longest = max(longest, j);
        }
        return longest;
    }
};