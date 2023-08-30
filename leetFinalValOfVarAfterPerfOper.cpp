/*
*
//**************************************2011. Final Value of Variable After Performing Operations.*************************************

https://leetcode.com/problems/final-value-of-variable-after-performing-operations/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["--X","X++","X++"]
["++X","++X","X++"]
["X++","++X","--X","X--"]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Of the four possible signs, signs to increase value have '+' in index:1 and have '-' in index:1. We use this condition to 
// increase/decrease the value of res tracker and return res at the end of iter.







class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        int res=0;
        for(string&s:v) {
            if(s[1]=='+') res++;											// If curr. sign is either of "++X" or "X++", we inc. res.
            else res--;														// If curr. sign is either of "--X" or "X--", we dec. res.
        }
        return res;															// Returning final val of res after perf. all oper.
    }
};

