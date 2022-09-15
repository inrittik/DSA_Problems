class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> mp;
        sort(changed.begin(), changed.end());
        
        vector<int> ori;
        for(int c:changed){
            mp[c]++;
            if(c%2==0 && mp.count(c/2) && c!=0){
                ori.push_back(c/2);
                if(--mp[c/2]==0) mp.erase(c/2);
                if(--mp[c]==0) mp.erase(c);
            }
        }
        if(mp[0]%2==0) for(int i=0; i<mp[0]/2;++i) ori.push_back(0);
        if(ori.size()*2==changed.size()) return ori;
        else{
            vector<int> v;
            return v;
        }
    }
};