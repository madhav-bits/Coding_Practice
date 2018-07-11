/*
*
//**********************************************************362. Design Hit Counter.***************************************************

Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological 
order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["HitCounter","hit","hit","hit","hit","hit","getHits","hit","getHits","getHits"]
[[],[1],[1],[2],[3],[4],[4],[300],[300],[301]]




["HitCounter","hit","hit","hit","getHits","getHits","getHits","getHits","getHits","hit","getHits"]
[[],[2],[3],[4],[300],[301],[302],[303],[304],[501],[600]]





// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Queue based Design question. As, we need to track hits of previous 300 seconds, we maitain a queue to store hits of prev. 
// 300 seconds. In order that if at a particular second lot of hits were made, system wouldn't infuse queue with all those values.As, we maintian
// other var which tracks previously entountered value, timestamp. If once again, such is encountered, we just add the occurance to var.
// When asked for getHits,we remove any contents in queue which are older than 300 seconds to curr. timestamp.Then,we add sumQueue(tracks sum of 
// elem. of queue) and currSum(tracks #occuranes of curr. timestamp) and reutrn the sum.








class HitCounter {
public:
    /** Initialize your data structure here. */
    queue<pair<int,int>>q;													// Stores #hits and timestamps.
    int sumQueue=0, currSum=0, prev=0;								// Sum of elem. in queue/sum of #occur of curr. timestamp/curr. timestamp value.
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(timestamp==prev) currSum+=1;										// If curr. timestamp had already occured, just add the occurane.
        else {																// If the timestamp is occuring first time.
            sumQueue+=currSum;												// Add the prev. timestamp's #occurances to sumQueue.
            // cout<<"Pushing currVal: "<<currSum<<" for timestamp: "<<prev<<endl;
            q.push({currSum,prev});											// Add the prev. timestamp's #occurances,timeStamp to sumQueue
            currSum=1;														// Update the #occurances of curr. timestamp.
            prev=timestamp;													// Update the curr. timestamp.
        }
        while(!q.empty() && q.front().second<=timestamp-300){				// If timestamps' older than= 300sec than curr. timestamp, removig it.
            sumQueue-=q.front().first;										// Removing #occurances from sumQueue.
            q.pop();														// Removing the pair from the queue.
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() && q.front().second<=timestamp-300){				// If timestamps' older than= 300sec than curr. timestamp, removig it.
            sumQueue-=q.front().first;										// Removing #occurances from sumQueue.
            q.pop();
        }
        if(prev<=timestamp-300){											// If prev. timeStamp is >=300 seconds older to curr. timeStamp.
            currSum=0;														// Note #occurances of curr. timeStamp(=0 as getHits isn't a hit).
            prev=timestamp;													// Update prev. timeStamp to curr. timeStamp.
        }
        // cout<<"SumQueue: "<<sumQueue<<" and currSum: "<<currSum<<endl;
        return sumQueue+currSum;											// Return the total nuumber of hits in prev. 300 seconds.
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */