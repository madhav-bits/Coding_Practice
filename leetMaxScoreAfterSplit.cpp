/*
*
//****************************************1422. Maximum Score After Splitting a String.**************************************

https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/


Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left 
substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3
 

Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only.



*****************************************************************TEST CASES:**********************************************************
//These are the examples I had tweaked and worked on.


"10101011110001000011"



"00001111"



"111100000"


"10011110001011000001100110"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Score if 0s in left part+1s in right part of the array after the split. We iter. over all possi.
// splits, calc. the score at each possib. and update the maxm. score. In order to get right part 1s, we calc. total 1s and subtract
// 1s encountered till now(left part), we add right part 1s with left part 0s and try to update the maxm. score of all possible splits.







class Solution {
public:
    int maxScore(string s) {
        int totalOnes=0, res=0;												// Stores the total 1s and the max. score.
        for(auto ch:s){														// Calc. total 1s, 0s.
            if(ch=='1') totalOnes++;
        }
        int zeroes=0, ones=0, remOnes=-1;									// Tracks zeroes, ones in indies iter. till then.
        for(int i=0;i<s.length()-1;i++){									// Iter. over entire array.
            if(s[i]=='0') zeroes++;											// Cnt. zeroes, ones.
            else ones++;
            remOnes=totalOnes-ones;											// Calc. ones in the right part.
            res=max(res, zeroes+remOnes);									// Adding left part 0s, right part 1s and updating max score.
        }
        return res;															// Returning the maxm. score.
    }
};