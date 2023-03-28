/*
*
//******************************************************1893. Check if All the Integers in a Range Are Covered.******************************************************

https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[3,4],[5,6]]
2
5
[[1,10],[10,20]]
21
21
[[1,10],[10,20],[22,24]]
22
24



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Prefix Sum based. Here, since the range of intervals is small. I used a int. array to mark the start, close int values on the array with +1, -1 resp. So, that while iter.
// i count the value stored in the indices, which shows #open intervals, if for any index the #open interval is zero, that means it's not covered by any interval, so we return false, if we reach 
// end of the range of ints, that means all ints are covered, so we return true.







class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>occur(52,0);
        for(vector<int>&u:ranges) {																		// Iter. over all intervals, marking the intervals in int array.
            occur[u[0]]++;																				// Marking start of interval with +1, so prefixSum #open. inter would reflect this open interval.
            occur[u[1]+1]--;																			// Marking end of interval with -1, so prefixSum would reflect this closed interval.
        }
        int open=0;
        for(int i=1;i<=right;i++) {																		// Iter. over range of ints in question.
            open+=occur[i];																				// Updating the curr. open intervals count.
            if(open==0 && i>=left) return false;														// If an int in the range of ints in concern is not covered, we return false.
        }
        return true;																					// If all concerned ints are covered, we return true.
    }
};

