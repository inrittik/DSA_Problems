class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> merged;
        double ans;
        while(i<m and j<n){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i++]);
            }
            else if(nums1[i]>nums2[j]){
                merged.push_back(nums2[j++]);
            }
            else{
                merged.push_back(nums1[i++]);                                               merged.push_back(nums2[j++]);

            }
        }
        while(i<m){
            merged.push_back(nums1[i++]);
        }
        while(j<n){
            merged.push_back(nums2[j++]);
        }
        if((m+n)%2!=0){
            ans = merged[(m+n)/2];
        }
        else{
            ans = (merged[(m+n)/2]+merged[(m+n)/2-1]);
            ans/=2;
        }
        return ans;
    }
};