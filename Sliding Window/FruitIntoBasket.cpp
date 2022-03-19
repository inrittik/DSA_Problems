// Fruit Into Basket

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0, j=0;
        unordered_map<int, int> mp;
        int mx=INT_MIN;
        if(n==1) return 1;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()==2){
                mx=max(mx, j-i+1);
            }
            else if(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        if(mx==INT_MIN) return n;
        return mx;
    }
};