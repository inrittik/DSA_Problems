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
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(int num:nums){
            trie->insert(num);
        }
        
        int mxxor = 0;
        for(int num:nums){
            mxxor = max(trie->getMax(num), mxxor);
        }
        
        return mxxor;
    }
};