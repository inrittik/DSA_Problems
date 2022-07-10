class Solution {
public:
    unordered_map<int, int> vis;
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(vis.count(n)==0){
            if(n%2==0) return vis[n]=1+integerReplacement(n/2);
            else{
                return vis[n]=2+min(integerReplacement(n/2), integerReplacement(n/2+1));
            }
        }
        return vis[n];
    }
};