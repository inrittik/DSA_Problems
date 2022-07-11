class Solution {
public:
    unordered_map<string, vector<int>> dp;
    vector<int> helper(string s){
        int n = s.size();
        vector<int> ans;
        for(int k=0; k<n; k++){
            char cur = s[k];
            if(s[k]=='+' || s[k]=='*' || s[k]=='-'){
                vector<int> left;
                vector<int> right;
                string temp_l = s.substr(0, k);
                string temp_r = s.substr(k+1);
                if(dp.count(temp_l)!=0) left = dp[temp_l];
                else left = helper(temp_l);
                
                if(dp.count(temp_r)!=0) right = dp[temp_r];
                else right = helper(temp_r);

                for(auto l:left){
                    for(auto r:right){
                        int val = 0;
                        if(s[k]=='*') val = l*r;
                        else if(s[k]=='+') val = l + r;
                        else val = l - r;

                        ans.push_back(val);
                    }
                }
            }
            
        }
        if (ans.empty())
			ans.push_back(atoi(s.c_str()));

        return dp[s]=ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};