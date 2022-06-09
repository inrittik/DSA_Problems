class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indi;
        int lo = 0, hi = numbers.size()-1;
        while(lo<hi){
            if(numbers[lo]+numbers[hi]==target){
                indi.push_back(lo+1);
                indi.push_back(hi+1);
                return indi;
            }
            else if(numbers[lo]+numbers[hi]<target){
                lo++;
            }
            else hi--;
        }
        indi.push_back(-1);
        indi.push_back(-1);
        return indi;
    }
};