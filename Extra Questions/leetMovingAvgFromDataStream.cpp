/*
*
//******************************************************346. Moving Average from Data Stream.***********************************************

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["MovingAverage","next","next","next","next"]
[[3],[1],[10],[3],[5]]







// Time Complexity: O(1).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(n).	
// This algorithm is Queue based. We store the max. possible len. of the Window allowed. When the window size isn't reached. We add the curr. num
// to the sum of elem. in window and calc. avg and return it. If window size is already reached, we pop the first elem. and add the curr. num
// and calc. the sum freshly, here, We need to remove the contribution of popped elem. to the sum and add the curr. num to the sum.








class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int>q;															// Queue to store contents of window.
    int limit;																// Stores the max. size of window allowed.
    double sum=0;															// Stores the sum of elem. in window.
    MovingAverage(int size) {
        limit=size;															// Updating the allowed window size var.
    }
    
    double next(int val) {
        if(q.size()==limit){												// If window size is already reached.
            sum-=q.front();													// We remove first elem. from window, sum.
            q.pop();
            q.push(val);													// Add. curr. elem. to the queue, sum.
            sum+=val;
            return sum/limit;												// Return the updated avg.
        }
        else{																// If window size isn't reached.
            q.push(val);													// Add curr. num to the window, sum.
            sum+=val;	
            return sum/q.size();											// Calc. avg. and return.
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */