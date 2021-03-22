/*
*
//****************************************************1796. Second Largest Digit in a String.***********************************************

https://leetcode.com/problems/second-largest-digit-in-a-string/


Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.

 

Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit. 
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"dfa12321afd"
"abc1111"
"abcd"
"abcd6465"
"abcd6464"
"65335432897"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, if a char is digit, if it's more than largest digit till then we update first and second largest digits,
// if it is <firstLarge and >secondLarge we update secondLarge. We return secondLarge at the end of iteration.











class Solution {
public:
    int secondHighest(string s) {
        int firstLarge=-1, secondLarge=-1;									// Tracks first and second largest digits in string.
        for(char ch:s){
            if(isdigit(ch)){												// If the char is a string.
                int val=ch-'0';
                if(val>firstLarge){											// If>firstLarge, update first and secondLarge.
                    secondLarge=firstLarge;
                    firstLarge=val;
                }else if(firstLarge>val && val>secondLarge) secondLarge=val;// If>secondLarge and <firstLarge, update secondLarge.
            }
        }
        return secondLarge;													// Returning second largest digit in the string.
    }
};
