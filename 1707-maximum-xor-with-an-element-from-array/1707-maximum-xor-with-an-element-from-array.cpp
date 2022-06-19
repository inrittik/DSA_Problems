struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    
    Node* getRef(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; --i){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->getRef(bit);
        }
    }
    
    int getMax(int x){
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; --i){
            int bit = (x>>i) & 1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->getRef(1-bit);
            }
            else{
                node = node->getRef(bit);
            }
        }
        
        return maxNum;
    }
};

class Solution {
public:
    static bool comp(vector<int>& a, vector<int> &b) {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for(int i=0; i<n; ++i){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), comp);
        
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        
        Trie trie;
        int ind = 0;
        for(int i=0; i<n; ++i){
            while(ind<nums.size() && nums[ind]<=queries[i][1]){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[queries[i][2]] = -1;
            else ans[queries[i][2]] = trie.getMax(queries[i][0]);
        }
        
        return ans;
    }
};