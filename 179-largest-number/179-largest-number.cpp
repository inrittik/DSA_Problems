class Solution {
public:
    static bool comp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        for(int i=0; i<n; ++i){
            res.push_back(to_string(nums[i]));
        }
        sort(res.begin(), res.end(), comp);
        string ans = "";
        for(int i=0; i<n; ++i) ans+=res[i];
        if(ans.length()>n) return ans;
        else return to_string(stoll(ans));
    }
};