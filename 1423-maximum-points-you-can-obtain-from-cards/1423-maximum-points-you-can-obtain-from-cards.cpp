class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=0; i<n; ++i) sum+=cardPoints[i];
        if(n==k) return sum;
        int w=n-k;
        int i=0, j=0;
        int preSum=0;
        int mnSum=INT_MAX;
        while(j<n){
            preSum+=cardPoints[j];
            if(j-i==w-1){
                mnSum=min(preSum, mnSum);
                preSum-=cardPoints[i];
                i++;
            }
            j++;
        }
        
        return sum-mnSum;
    }
};