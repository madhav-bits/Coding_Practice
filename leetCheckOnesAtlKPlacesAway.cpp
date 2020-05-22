/*
*
//***********************************1437. Check If All 1's Are at Least Length K Places Away.***********************************

https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/


Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise 
return False.

 

Example 1:



Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:



Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
 

Constraints:

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] is 0 or 1




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,0,0,1,0,0,0,1,1]
3



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we will make sure that the gap between consecutive ones is >=k, if this is true, then
// the dist. b/w all pairs of ones is >=k.






class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
        int prev=-1;														// Stores the index of last encountered one.
        for(int i=0;i<v.size();i++){										// Iter. over array.
            if(v[i]==0) continue;											// If it is zero, skip it.
            if(prev!=-1 && i-prev-1<k) return false;						// Calc. gap b/w last and curr. one. If <k return false.
            prev=i;															// Store curr. one's index.
        }
        return true;														// If all gaps are acc. to requirement, return true.
    }
};