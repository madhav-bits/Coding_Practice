/*
*
//******************************************************2745. Construct the Longest New String.******************************************************

https://leetcode.com/problems/construct-the-longest-new-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2
5
1
3
2
2
4
4
5



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is observation based. Here since "AB" can be used consecutively wihtout any wastage and can be sliced any x/y type of words without any issue and since
// we can use x, y alternatively, we first try to fully use the least occuring word and one more word if(x>y or y>x), after this we append z words at the front or the back
// consecutively, this would be the max possible string length.







class Solution {
public:
    int longestString(int x, int y, int z) {
        int res=(x!=y);														// If x,y are unequal we get one word of a type extra time.
        res+=2*min(x, y);													// x, y words alternating each other.
        res+=z;																// Appending z words at the front for x>y and at end if y>=x.
        return 2*res;														// Returning the total length of the string.
    }
};

