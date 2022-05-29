class Solution {
public:
    int cnt;
    void merge(vector<int>& nums, int lo, int mid, int hi){
        int j=mid;
        for(int i=lo; i<=mid-1; ++i){
            while(j<=hi && nums[i]>2*((long)nums[j])) j++;
            
            cnt+=j-mid;
        }
        
        sort(nums.begin()+lo, nums.begin()+hi+1);
    }
    void mergeSort(vector<int>& nums, int lo, int hi){
        int mid, cnt=0;
        if(lo>=hi) return;

        mid=lo+(hi-lo)/2;

        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);

        merge(nums, lo, mid+1, hi);
        return;
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
        mergeSort(nums, 0, nums.size()-1);
        
        return cnt;
    }
};