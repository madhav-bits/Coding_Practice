/*
*
//******************************************************1894. Find the Student that Will Replace the Chalk.******************************************************

https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,1,5]
22
[3,4,1,2]
25
[5,7,4,2,8,9,123,13,46,3,65,3,5,8,56,43,58,73,29,75,4,90]
234538



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. As the students take turns in a cyclic way, we first calc. the #chalks needed for each cycle of students. We cover all the cycles of usage by doing
// totalChalks%chalksPerCycle, so now we iter. over the students to find which student has to refill chalks as #chalks would recently reach zero in this iteration. If curr. chalk<#chalksNeeded for 
// the curr. student, we return that index.







class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int total=accumulate(chalk.begin(), chalk.end(), 0ll);								// Calc. chalks per cycle.
        k%=total;
        for(int i=0;i<chalk.size();i++) {																// Iter. over cycle of students.
            if(k<chalk[i]) return i;																	// If curr. chalks left<chalksNeeded for this student, we return this index.
            k-=chalk[i];																				// Giving chalks to curr. student to use and updating rem. chalks count.
        }
        return -1;																						// Default return value.
    }
};

