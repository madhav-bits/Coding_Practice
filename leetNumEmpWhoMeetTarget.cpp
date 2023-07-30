/*
*
//**********************************************2798. Number of Employees Who Met the Target.********************************************

https://leetcode.com/problems/number-of-employees-who-met-the-target/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,2,3,4]
2
[5,1,4,2,2]
6



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over employees hours and count those which are >=target hours and return the #employees satisfying the requirement at the 
// end of iter.








class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res=0;
        for(int&num:hours) {
            if(num>=target) res++;											// Tracking #emp satisfying the given requirement.
        }
        return res;															// Returning #emp satisfying the given requirement.
    }
};

