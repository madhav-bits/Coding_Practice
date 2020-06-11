/*
*
//************************************************1400. Construct K Palindrome Strings.*********************************************

https://leetcode.com/problems/construct-k-palindrome-strings/description/


Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
Example 4:

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.
Example 5:

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
 

Constraints:

1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"annabelle"
2

"leetcode"
3

"yzyzyzyzyzyzyzy"
2

"true"
4


"cr"
7


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we want to k palindromes using given chars from a str. The main issue we have to worry of
// while forming palindromes is #odd numbered chars we have. As, each palindrome can have one odd numbered char., if #odd numbered chars
// are>k, then we can't fit in all odd chars. Based on the remaining palindromes to be formed, we can split the even numbered chars
// and place them in empty palindromes as required, it would be able to fill all possible remaining palindromes.








class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;										// Base case.
        vector<int>occur(26,0);
        for(auto ch: s) occur[ch-'a']++;									// Couting #occur. of each char.
        int evenPairs=0, odds=0;
        for(int i=0;i<26;i++){
            evenPairs+=occur[i]/2;											// Counting #pairs with even occurrences.
            odds+=occur[i]%2;												// Counting #chars with odd #occurrences.
        }
        if(odds>k) return false;											// If odd chars>k, we can't form required palindromes.
        return true;														// No issues found, return true.
    }
};
