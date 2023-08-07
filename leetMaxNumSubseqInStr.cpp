/*
*
//*******************************************2207. Maximize Number of Subsequences in a String.******************************************

https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abdcdbc"
"ac"
"aadb"
"ab"
"alkajalgjtiaglkad"
"aa"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Since the pattern is of length 2, we use two pointers to track #occur. of first, second char in the string. During iter. if curr. char is 
// t[1], we can map it with all first char which occurred earlier, so we add #occur. of first char to res, we inc. the #occur of second char. If it is first char, we inc. the 
// #occur. of first char. One exception is that is t[0] and t[1] are same chars, then we have to inc. #occur. of first, second char in same iter., in such case we first add 
// #occur. of first char to res and then inc. #occur. of both first, second chars. By adding t[0] at the beginning or by adding t[1] at the end of text we can maximize the 
// #newly formed patterns with these new chars, we find the max of the both cases and add it to res and return res.







class Solution {
public:
    long long maximumSubsequenceCount(string text, string t) {
        long long int res=0;
        int zeroIndexCount=0, oneIndexCount=0;
        for(char&ch:text) {													// Iter. over entire string.
            if(ch==t[1]) {													// If curr. char is second char of t.
                res=res+zeroIndexCount;										// Curr. char maps with all prev. occur of first char to form str: "t".
                oneIndexCount++;											// Inc. the #occur. of second char.
            }
            if(ch==t[0]) zeroIndexCount++;									// Inc. the #occur of first char.
        }
        return max(res+zeroIndexCount, res+oneIndexCount);					// Returning the max possible patterns formed after adding either of the chars to "text".
    }
};


