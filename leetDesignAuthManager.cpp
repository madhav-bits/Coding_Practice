/*
*
//******************************************************1797. Design Authentication Manager.*****************************************************

https://leetcode.com/problems/design-authentication-manager/


There is an authentication system that works with authentication tokens. For each session, the user will receive a new authentication token that 
will expire timeToLive seconds after the currentTime. If the token is renewed, the expiry time will be extended to expire timeToLive seconds after 
the (potentially different) currentTime.

Implement the AuthenticationManager class:

AuthenticationManager(int timeToLive) constructs the AuthenticationManager and sets the timeToLive.
generate(string tokenId, int currentTime) generates a new token with the given tokenId at the given currentTime in seconds.
renew(string tokenId, int currentTime) renews the unexpired token with the given tokenId at the given currentTime in seconds. If there are no 
unexpired tokens with the given tokenId, the request is ignored, and nothing happens.
countUnexpiredTokens(int currentTime) returns the number of unexpired tokens at the given currentTime.
Note that if a token expires at time t, and another action happens on time t (renew or countUnexpiredTokens), the expiration takes place before 
the other actions.

 

Example 1:


Input
["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
Output
[null, null, null, 1, null, null, null, 0]

Explanation
AuthenticationManager authenticationManager = new AuthenticationManager(5); // Constructs the AuthenticationManager with timeToLive = 5 seconds.
authenticationManager.renew("aaa", 1); // No token exists with tokenId "aaa" at time 1, so nothing happens.
authenticationManager.generate("aaa", 2); // Generates a new token with tokenId "aaa" at time 2.
authenticationManager.countUnexpiredTokens(6); // The token with tokenId "aaa" is the only unexpired one at time 6, so return 1.
authenticationManager.generate("bbb", 7); // Generates a new token with tokenId "bbb" at time 7.
authenticationManager.renew("aaa", 8); // The token with tokenId "aaa" expired at time 7, and 8 >= 7, so at time 8 the renew request is ignored, and nothing happens.
authenticationManager.renew("bbb", 10); // The token with tokenId "bbb" is unexpired at time 10, so the renew request is fulfilled and now the token will expire at time 15.
authenticationManager.countUnexpiredTokens(15); // The token with tokenId "bbb" expires at time 15, and the token with tokenId "aaa" expired at time 7, so currently no token is unexpired, so return 0.
 

Constraints:

1 <= timeToLive <= 108
1 <= currentTime <= 108
1 <= tokenId.length <= 5
tokenId consists only of lowercase letters.
All calls to generate will contain unique values of tokenId.
The values of currentTime across all the function calls will be strictly increasing.
At most 2000 calls will be made to all functions combined.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["AuthenticationManager","renew","generate","countUnexpiredTokens","generate","renew","renew","countUnexpiredTokens"]
[[5],["aaa",1],["aaa",2],[6],["bbb",7],["aaa",8],["bbb",10],[15]]
["AuthenticationManager","countUnexpiredTokens","renew","generate","renew","countUnexpiredTokens","renew","generate","countUnexpiredTokens","countUnexpiredTokens","countUnexpiredTokens"]
[[28],[2],["xokiw",6],["ofn",7],["dses",15],[17],["ofzu",19],["dses",20],[23],[27],[30]]




// Ammortized Time Complexity: O(1).													// Generate- O(1), Renew:O(1), CountValidTokens:O(1)
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Ammortized Time Complexity: O(1).													// Generate- O(1), Renew:O(1), CountValidTokens:O(1)
// Space Complexity: O(n).	
// This algorithm is Queue and Hash Map based. Here, we store the tokenId and it's expiry time in the queue. Whenever we receive an renew or count tokens
// request, we firt remove all tokens which are expired. While renewing an existing token, we update token with updated time in the map and add new 
// entry into queue. While removing expired tokens from queue, we only remove those entries from map whose expirty time is same as the one in queue, which 
// indicates this is the latest update on that tokenId. We return map size, as queue might contain duplicates when tokens are renewed.









class AuthenticationManager {
public:
    queue<pair<string,int>>q;												// Keep track of tokens based on their expiry times.
    unordered_map<string,int>m;												// Keep track of latest expiry time update on the tokens.
    int timeToLive;
    AuthenticationManager(int timeToLive) {
        m=unordered_map<string,int>();
        q=queue<pair<string,int>>();
        this->timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId]=currentTime+timeToLive;									// Insert new token and expiry time entries into queue and map.
        q.push({tokenId, currentTime+timeToLive});
        return ;
    }
    
    void renew(string tokenId, int currentTime) {
        while(!q.empty() && q.front().second<=currentTime){					// Remove all tokens which are expired.
            if(q.front().second==m[q.front().first]) m.erase(q.front().first);// Remove map entry as this is the latest update on this token.
            q.pop();
        }
        if(m.count(tokenId)==0) return ;									// If this token is expired by current time, skip renewing it.
        m[tokenId]=currentTime+timeToLive;									// Renew token and add new entry into queue.
        q.push({tokenId, currentTime+timeToLive});							// Update expiry time in map.
        return ; 
    }
    
    int countUnexpiredTokens(int currentTime) {
        while(!q.empty() && q.front().second<=currentTime){					// Remove all expired tokens in queue by current time.
            if(q.front().second==m[q.front().first]) m.erase(q.front().first);
            q.pop();
        }
        return m.size();													// Return count of unexpired tokens.
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
