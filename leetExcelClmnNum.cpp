/*
*
//******************************************************171. Excel Sheet Column Number.***********************************************

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"AAB"
"ZZ"
"A"
"ZA"
""




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is converting the chars with base-26 into int.


class Solution {
public:
    int titleToNumber(string s) {
        int res=0;																// Stores the int value at any point of time.
        for(int i=0;i<s.length();i++){
            res=res*26+(s[i]-'A'+1);											// Converting the chars with base-26 into int.
        }
        return res;																// Returning the int. value.
    }
};