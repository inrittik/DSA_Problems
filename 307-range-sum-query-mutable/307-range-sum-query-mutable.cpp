class NumArray {
    const int N = 100000;
public:
    vector<int> seg;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(N);
        for (int i=0; i<n; i++)   
        seg[n+i] = nums[i];
     
        for (int i = n - 1; i > 0; --i)    
            seg[i] = seg[i<<1] + seg[i<<1 | 1]; 
    }
    
    void update(int index, int val) {
        seg[index+n] = val;
        index = index+n;

        // move upward and update parents
        for (int i=index; i > 1; i >>= 1)
            seg[i>>1] = seg[i] + seg[i^1];
    }
    
    
    int sumRange(int l, int r) {
        int res = 0;
        r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1)
                res += seg[l++];

            if (r&1)
                res += seg[--r];
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */