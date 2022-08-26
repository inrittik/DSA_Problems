class Twitter {
public:
    unordered_map<int, set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    long long time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap; 
        for (auto it=tweets[userId].begin();it!=tweets[userId].end();++it)
            maxHeap.push(*it);
        for (auto it1=follows[userId].begin();it1!=follows[userId].end();++it1){
            int usr = *it1; 
            for (auto it2=tweets[usr].begin();it2!=tweets[usr].end();++it2)
                maxHeap.push(*it2);
        }   
        vector<int> res;
        while(maxHeap.size()>0) {
            res.push_back(maxHeap.top().second);
            if (res.size()==10) break;
            maxHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */