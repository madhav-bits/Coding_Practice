/*
*
//********************************1456. Maximum Number of Vowels in a Substring of Given Length.***********************************

https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/



Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"abciiidef"
3


"aeiou"
2


"leetcode"
3


"rhythms"
4


"tryhard"
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since we are working on fixed substring len, once we are at index>=len, we remove the 
// first char in the substring, if it is vowel, we dec. the cnt, we add curr. index and inc. cnt if if vowel. We update the res
// with #odds in the substring and try to maximize it.







class Solution {
public:
    int maxVowels(string s, int k) {
        int res=0, cnt=0;													// Track max. #vowels, curr. #vowels.
        for(int i=0;i<s.length();i++){										// Iter. over string.
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cnt++;	// If curr. is vowel, inc. the cnt.
            if(i>=k && (s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')) cnt--;// If rem. char is vowel, dec. cnt.
            res=max(res, cnt);												// Try to udpate the max #vowels.
        }	
        return res;															// Return the max. #vowels in substring.
    }
};

