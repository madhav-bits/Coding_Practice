/*
*
//************************************************************355. Design Twitter.*****************************************************

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets 
in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the 
user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]



["Twitter","postTweet","postTweet","postTweet","getNewsFeed","follow","follow","postTweet","postTweet","getNewsFeed","unfollow","getNewsFeed","getNewsFeed"]
[[],[1,5],[1,15],[1,17],[1],[1,2],[1,3],[2,6],[3,7],[1],[1,2],[1],[2]]



["Twitter","postTweet","postTweet","postTweet","getNewsFeed","follow","follow","postTweet","postTweet","getNewsFeed","unfollow","getNewsFeed","getNewsFeed"]
[[],[1,5],[1,15],[1,17],[1],[1,2],[1,3],[2,6],[3,7],[1],[1,2],[1],[2]]



["Twitter","postTweet","follow","getNewsFeed"]
[[],[1,5],[1,1],[1]]





// Time Complexity: O(n).													// Searches all friends of curr. user.  
// Space Complexity: O(n).													// To stores tweets of all users.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. When a user makes, a tweet, that tweetId along with timeStamp is saved in HashMap. When a getNewsFeed
// is performed, it goes through all it's followeees, and takes their top 10 feeds(as we need top 10 feeds) and push the into pq. After 
// iterating through all followees, we extract the top 10(most recent)tweets of a person and his followers.




class Twitter {
public:
    /** Initialize your data structure here. */
    struct compare{
        bool operator()(const auto&lt, const auto& rt){
            return lt.second<rt.second;
        }
    };
    unordered_map<int, map<int,int>> following;								// Maps a user with his followees.
    unordered_map<int, vector<pair<int,int>>> tweets;                       // First will be tweetID, and second will be time.
    int time=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;		// PQ, sorts based on time stamp, most recent one stays top.
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(tweetId,time));					// Saves tweetId with timestamp in map's curr. user key.
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        pq=priority_queue<pair<int, int>, vector<pair<int, int>>, compare>();// Emptying the Prio. Queue.
        vector<int>res;														// Stores 10 most recent tweets.
        int count=1;														// Keeps track of tweets scanned in curr. user from the last.
        map<int, int> m=following[userId];									// Extracts list of followees of curr. user.
        
        for(int i=tweets[userId].size()-1;i>=0 && count<=10;i--, count++){	// Extract top 10 tweets of curr. user and push into PQ.
            pq.push(tweets[userId][i]);
        }
        
        for(auto it=m.begin(); it!=m.end();it++){							// Iterating through all followees of curr. user.
            int curr=it->first;
            if(curr==userId) continue;
            count=1;
            for(int i=tweets[curr].size()-1;i>=0 && count<=10;i--, count++){// Extracting top 10 tweets of all followees.
                pq.push(tweets[curr][i]);
            }
        }
        // cout<<"Pq size is; "<<pq.size()<<endl;
        count=1;
        while(!pq.empty() && count<=10){									// After all iterations, extract top-10(top 10 most recent tweets).
            res.push_back(pq.top().first);
            count++;
            pq.pop();
        }
        return res;															// Return 10 recent tweets.
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
     following[followerId][followeeId]=1;   								// Setting/storing Follower and Followee relation in map.
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {							// Removing relation b/w follower and followee.
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */