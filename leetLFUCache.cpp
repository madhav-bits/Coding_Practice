/*
*
//*************************************************************460. LFU Cache.*****************************************************

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the 
least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have 
the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

/*
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]


["LFUCache","put","put","get","put","put","get","get","put","put","put","get","get","get"]
[[3],[1,1],[2,2],[1],[3,3],[4,14],[2],[3],[4,24],[5,5],[4,44],[1],[3],[4]]



// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, we maintain three maps to track count, key, value pairs, list of keys with same number of occurances.
// We also use set, to keep track of minFreq easily(Not much useful as time complexity is concerned in the test cases provided). Whenever,
// the capacity is reached, we remove the least recent(first) one in the list of keys with least #occurances. We iterate over least values of 
// set start until a valid  key is reached. As, this iteration happens as many times as there was an increment in #occurances, so it is O(1)
// ammortized complexity.
 
 
 
 // This algo. can even be optimzied by using Linked Lists isntead of queue to track least recent used ones same as LRU Cache.
 
 
 
 
 
 class LFUCache {
public:
    
    int maxm, len=0;
    unordered_map<int,set<int>>contents;                                	// Stores all keys with same number of occurrances as keys.
    unordered_map<int,int>occur;                                        	// Stores #num occurred.
    unordered_map<int,int>reln;                                          	// Stores key and value pairs.
    set<int>s;																// Tracks minFreq.
    unordered_map<int,queue<int>>recent;									// Tracks recent activities with that #occurances.
    LFUCache(int capacity) {
        maxm=capacity;
    }
    
    int get(int key) {
        // cout<<"Get req for key: "<<key<<endl;
        if(occur.count(key)==0) return -1;
        if(occur.count(key)==1)												// Delete the key from curr. #occurances.
            contents[occur[key]].erase(key);
        occur[key]++;														// Inc. the #occurances.
        s.insert(occur[key]);												// Inc. the new #occurances into set.
        // cout<<"INc. the count of key: "<<key<<" to : "<<occur[key]<<endl;
        contents[occur[key]].insert(key);									// Insert the key into map with #occurances as key.
        recent[occur[key]].push(key);										// Insert the key into map with recent acitivity as value.
        // cout<<"The result of get: "<<reln[key]<<endl;
        return reln[key];													// Return the value for that key.
    }
    
    void put(int key, int value) {
        // if(occur.count(key)==1) return; 
        // cout<<"Put key: "<<key<<" and len: "<<len<<endl;
        if(maxm==0) return ;
        if(occur.count(key)==0 && len==maxm){                             	// Removing the LFU elem.
            int minFreq=*s.begin();
            // cout<<"minFreq: "<<minFreq<<endl;
            while(recent[minFreq].size()>0 && contents[minFreq].count(recent[minFreq].front())==0){// If key is not with that many #occurances.
                // cout<<"Deleting back elem: "<<recent[minFreq].front()<<endl;
                recent[minFreq].pop();										// Remove keys which have moved from this list.
                if(recent[minFreq].size()==0){								// If the list with particular #occurances is empty, then delete the key.
                    s.erase(minFreq);
                    minFreq=*s.begin();										// Update the minFreq.
                    // cout<<"new minFreq: "<<minFreq<<endl;
                }
            }
            int elem=recent[minFreq].front();								// Extract the key that is least recent with minFreq .
            contents[minFreq].erase(elem);									// Erase the key from that minFreq occuring list.
            occur.erase(elem);												// Erase the key from occur map.
            // cout<<"minFreq: "<<minFreq<<" and deleted elem: "<<elem<<endl;
            len--;															// Dec. the num. of elem. in cache.
            if(contents[minFreq].size()==0){								// If no elem. in list with minFreq as key, then delete that key.
                contents.erase(minFreq);
                s.erase(minFreq);
            }
        }
        
        if(occur.count(key)==1){											// If key already present in Cache.
            contents[occur[key]].erase(key);								// Delete it from curr. #occurances.
            if(contents[occur[key]].size()==0){								// IF the list gets empty, then delete that #occurance key from map.
                contents.erase(occur[key]);
                s.erase(occur[key]);										// Delete it from set.
            }
            len--;
        }
        len++;
        occur[key]++;														// INc. the count of curr. key.
        // cout<<"Inserted val: "<<occur[key]<<endl;
        s.insert(occur[key]);												// Insert the new #occurances into set.
        reln[key]=value;													// Relate key, value pairs.
        contents[occur[key]].insert(key);									// Insert key with updated #occurances key.
        recent[occur[key]].push(key);										// Push the key into recent list of updated #occurances key.
        // cout<<"Inserted key: "<<key<<"and occure size: "<<occur[1]<<endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
 
 
 
 
 
 
 
 //************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is HashMap based. Here, we maintain three maps to track count, key, value pairs, list of keys with same number of occurances.
// We also use set, to keep track of minFreq easily(Not much useful as time complexity is concerned in the test cases provided). Whenever,
// the capacity is reached, we remove the least recent(first) one in the list of keys with least #occurances. We iterate over least values of 
// set start until a valid  key is reached. As, this iteration happens as many times as there was an increment in #occurances, so it is O(1)
// ammortized complexity.
 
 
 
 
 // The algo. is same as the above, one except that it is slightly optimized- set has been reomved, len has been removed(occur can serve the 
 // same purpose).
 
 
 
 
 
 class LFUCache {
public:
    
    int minFreq=INT_MAX, maxm;
    unordered_map<int,set<int>>contents;                                // Stores all keys with same number of occurrances as keys.
    unordered_map<int,int>occur;                                        // Stores #num occurred.
    unordered_map<int,int>reln;                                          // Stores key and value pairs.
    unordered_map<int,queue<int>>recent;
    LFUCache(int capacity) {
        maxm=capacity;
    }
    
    int get(int key) {
        // cout<<"Get req for key: "<<key<<endl;
        if(occur.count(key)==0) return -1;
        if(occur.count(key)==1)
            contents[occur[key]].erase(key);
        occur[key]++;
        minFreq=min(minFreq,occur[key]);
        // cout<<"INc. the count of key: "<<key<<" to : "<<occur[key]<<endl;
        contents[occur[key]].insert(key);
        recent[occur[key]].push(key);
        // cout<<"The result of get: "<<reln[key]<<endl;
        return reln[key];
    }
    
    void put(int key, int value) {
        // cout<<"Put key: "<<key<<" and len: "<<len<<endl;
        if(maxm==0) return ;
        if(occur.count(key)==0 && occur.size()==maxm){                                                  // Removing the LFU elem.
            while(recent[minFreq].size()>0 && contents[minFreq].count(recent[minFreq].front())==0){
                // cout<<"Deleting back elem: "<<recent[minFreq].front()<<endl;
                recent[minFreq].pop();
                if(recent[minFreq].size()==0){
                    minFreq++;
                    // cout<<"new minFreq: "<<minFreq<<endl;
                }
            }
            int elem=recent[minFreq].front();
            contents[minFreq].erase(elem);
            occur.erase(elem);
        }
        
        if(occur.count(key)==1){
            contents[occur[key]].erase(key);
        }
        occur[key]++;
        minFreq=min(minFreq,occur[key]);
        // cout<<"Inserted val: "<<occur[key]<<endl;
        reln[key]=value;
        contents[occur[key]].insert(key);
        recent[occur[key]].push(key);
        // cout<<"Inserted key: "<<key<<"and occure size: "<<occur[1]<<endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */