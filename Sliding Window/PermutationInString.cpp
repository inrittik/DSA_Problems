// Leetcode - Permutation in String 567

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int k=s1.size();
        int i=0, j=0;
        unordered_map<char, int> mp;
        for(i=0; i<k; ++i){
            mp[s1[i]]++;
        }
        int count=mp.size();
        i=0;
        while(j<n){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0){
                    count--;
                }
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(count==0) return true;
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]]==1){
                        count++;
                    }
                }
                i++, j++;
            }
        }
        return false;
    }
};