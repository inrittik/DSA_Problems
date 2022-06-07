class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i=nums1.begin(), j=nums2.begin();
        nums1.erase(nums1.end()-n, nums1.end());
        while(i<nums1.end() && j<nums2.end()){
            if(*i>*j){
                nums1.insert(i, *j);
                j++;
            }
            i++;
        }
        // nums1.erase(nums1.end()-n, nums1.end());
        while(j<nums2.end()){
            nums1.push_back(*j);
            j++;
        }
    }
};