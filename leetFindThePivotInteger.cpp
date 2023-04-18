/*
*
//******************************************************2485. Find the Pivot Integer.******************************************************

https://leetcode.com/problems/find-the-pivot-integer/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


8
5
4
1
1000
342



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we observe the monotonic nature of the sum of values on left, right side of any probable pivot number, as pivot number inreases, leftSum inc and
// rightSum dec. So, we use binary search to find the pivot number. If leftSum<rightSum, the pivot number is towards right so we focus on right part, if leftSum>rightSum, the pivot number would be
// on left side, so we focus on left side. If leftSum==rightSum we return the pivot number.







class Solution {
public:
    int pivotInteger(int n) {
        int total=(n*(n+1))/2;
        int low=1, high=n;
        while(low<=high) {																				// Binary Search in the probable pivot range.
            int mid=(low+high)/2;
            int left=(mid*(mid+1))/2;																	// Calc. left part total.
            int right=total-left+mid;																	// Calc. right part total.
            if(left==right) return mid;																	// If totals on both sides are equal, we return the pivot number.
            if(left<right) low=mid+1;																	// If leftSum<rightSum focus on right part.
            else high=mid-1;																			// Else focus on the left part.
        }
        return -1;																						// If no pivot number found, return -1.
    }
};
