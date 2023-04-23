/*
*
//******************************************************2651. Calculate Delayed Arrival Time.******************************************************

https://leetcode.com/problems/calculate-delayed-arrival-time/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


15
5
13
11
16
9
20
24
23
23
23
24
1
23
1
22
1
20



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is math based. We calc. final time and convert it to 24 hr format using modulo 24 and return the resulting time.







class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime+delayedTime)%24;															// Convert into 24 hr format and return the time.
    }
};

