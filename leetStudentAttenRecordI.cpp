/*
*
//******************************************************551. Student Attendance Record I.***********************************************

You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"PPLLAL"

"LPPLLALA"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. On iteration, we keep track of #absent days, he had. We also keep track of conse. days child is late.
// If any of absent days,conse. late days crosses conditions for reward, we return false.








class Solution {
public:
    bool checkRecord(string s) {
        int count=0, state=0;												// Tracks #absent days, cosec. late days.
        for(int i=0;i<s.length();i++){										// Iterate the entire array.
            if(s[i]=='A'){													// If absent inc. the count.
                count++;
                if(count==2) return false;									// If condition violated, return false.
            }
            if(s[i]=='L') state++;											// Tracking conse. days late.
            else state=0;													// If not late, set the count=0.
            if(state>2) return false;										// I condition violated, return false.
        }
        return true;														// If no issues arises(conditions violated), return true.
    }
};