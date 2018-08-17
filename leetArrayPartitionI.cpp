/*
*
//**************************************************************561. Array Partition I.*******************************************************

Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes 
sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,3,2,6,5]

[1,4,3,2,6,5,10,20]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is observation based. So, as to get an int. counted towards final res, one other num has to be sacrificed. We sort our given 
// nums. For including num-i, one of digits greater than it has to be sacrificed, of those nums, if we sacrifice num. closest to it, then the 
// damage to the final count would be minm. Thus, we choose alternating nums from the start and add them to final result. At the end of iter.
// return the result.








class Solution {
public:
    int arrayPairSum(vector<int>& v) {
        int res=0;															// Tracks the sum of min. values.
        sort(v.begin(), v.end());											// Sort the given nums.
        for(int i=0;i<v.size();i+=2){										// Choose alternating nums. from the start till end.
            res+=v[i];														// Add chosen nums to result var.
        }
        return res;															// Return the result.
    }
};