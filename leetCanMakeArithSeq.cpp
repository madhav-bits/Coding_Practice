/*
*
//*******************************************1502. Can Make Arithmetic Progression From Sequence.*******************************************

https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/



Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive 
elements is the same.

Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 

Constraints:

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[2,6,10,4,8]


[3,5,9,6]

[4,3]



// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is sorting based. We sort the array, we check all consec. values have same gap. If not we return false.







class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& v) {
        sort(v.begin(), v.end());											// Sorting the array.
        int diff=v[1]-v[0];													// Calc. arith seq. gap.
        for(int i=2;i<v.size();i++){										// Iter. over array.
            if(v[i]-v[i-1]!=diff) return false;								// If curr. gap!=expected gap, return false.
        }
        return true;														// If all pairs have same gap, return true.
    }
};