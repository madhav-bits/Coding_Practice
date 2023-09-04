/*
*
//**************************************2042. Check if Numbers Are Ascending in a Sentence.***************************************

https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1 box has 3 blue 4 red 6 green and 12 yellow marbles"
"sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
"hello world 5 x 5"
"sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
"1 2 3 3 4 5"
"1 2 3 4"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We extract nums as we iterate in the string, once we reach  ' ' char if curr num is non-zero, which means we just finished
// iterating over number, we compare this with prev. num, if prev>=num, we return false else we update prev. num with curr. value and set curr. val=0 and 
// continue the process. If we reached end of string without any issues we return true.







class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev=-1, curr=0;
        for(char&ch:s) {
            if(ch==' ') {													// If we encounter ' ' bar.
                if(curr>0 && prev>=curr) return false;						// If we just finished iter. over num and is <= prev. num, we return false.
                if(curr>0) prev=curr;										// If prev. char is a number, we set prev. num to curr. num.
                curr=0;														// Set curr. num to zero.
            } else if(isdigit(ch)) curr=curr*10+(ch-'0');
        }
        if(curr>0 && prev>=curr) return false;								// Comparing if last non-space char is a number.
        return true;														// If all nums in the array are in Ascending order.
    }
};

