/*
*
//******************************************************1446. Consecutive Characters.***********************************************

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with examples provided with the question.


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we need max. substr len with same char. We iter. over str and we cnt as long as we 
// encounter same char as prev. If different we try to update max. substr len with count, we repeat this till end of string.







class Solution {
public:
    int maxPower(string s) {
        if(s.length()==1) return 1;											// Base case.
        int res=1, cnt=1;
        for(int i=1;i<s.length();i++){										// Iter. over string.
            if(s[i]==s[i-1]) cnt++;											// If same chars, we inc. the count.
            else{															// If diff. chars, update the maxm. cnt.
                res=max(res, cnt);
                cnt=1;														// Init. the cnt to 1.
            }
        }
        res=max(res, cnt);													// Update maxm. cnt with last set of same chars cnt.
        return res;															// Reutrn the maxm. cnt.
    }
};