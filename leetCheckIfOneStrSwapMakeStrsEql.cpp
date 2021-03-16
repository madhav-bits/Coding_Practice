/*
*
//********************************************1790. Check if One String Swap Can Make Strings Equal.*******************************************

https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/


You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string 
(not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
Example 4:

Input: s1 = "abcd", s2 = "dcba"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"bank"
"kanb"
"abcd"
"efgh"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. For both the strings to be equal after swap, they have to be anagrams, we check for anagrams, we also count 
// #indices where the chars are different, the #indices has to be either 0 or 2, if it's anything else two strings can't be equal after at max one swap.










class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        int diff=0;
        int swaps=0;
        vector<int>occur(26,0);												// Tracking #occur. of each char.
        for(int i=0;i<s.length();i++){
            occur[s[i]-'a']++;												// Calc. diff. in #occur. of each char.
            occur[t[i]-'a']--;
            if(s[i]!=t[i]) swaps++;											// Tracking #indices with diff. chars.
        }
        for(int i=0;i<26;i++){
            if(occur[i]!=0) return false;									// If string aren't anagrams, return false.
        }
        return (swaps==0 || swaps==2);										// If #indices with diff. char are !=0 and !=2, then swap won't be effective.
    }
};

