/*
*
//******************************************************2769. Find the Maximum Achievable Number.******************************************************

https://leetcode.com/problems/find-the-maximum-achievable-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4
1
7
2
20
9
1
2
1
1



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy Approach based. Here, we are looking for max. number, so it has to be more than target number, also reachbable in at max. t secs.
// We can cover max. gap in t seconds if both res and target moves towards each other in every step, so we place res number, 2*t above the target number, so
// now in every step both of them move towards each other and meet at target+t at t seconds.







class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num+2*t;														// Returning Max. Achievable Number.
    }
};

