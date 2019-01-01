/*
*
//**********************************************************482. License Key Formatting.***************************************************

You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 
groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which 
could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all 
lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2

Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned 
above.
Note:
1) The length of string S will not exceed 12,000, and K is a positive integer.
2) String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
3) String S is non-empty.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"2-5g-3-Ja"
2




"2-5g-3-Ja"
1





"2-5g-3-Ja"
3




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we iter. over given str in reverse drn, as for the first interval we need not have required block 
// # of chars. While iter. we count the #chars printed till that instant, if we have a char to print #chars printed till then is multiple of 
// block size, then we add '-' char and the curr. char we want to print, thus we meet all requirements of the question.








class Solution {
public:
    string licenseKeyFormatting(string s, int K) {
        string res="";														// Stores the final result str.
        int count=0;														// Tracks the #chars printed till that instant.
        for(int i=s.length()-1;i>=0;i--){									// Iter. over entire string.
            if(s[i]=='-') continue;											// Skip the '-' chars.
            
            if(count>0 && count%K==0) res+='-';								// If we have multiples of 'k' chars at any instant,add '-'.
																			// While looking to add new char.
            if(s[i]>=97 && s[i]<=122) res+=s[i]-32;							// If curr. char is lower case char, convert it to upper case.
            else res+=s[i];   												// For rest of chars, just append it.
            count++;														// Count the #chars printed.
            
        }
        reverse(res.begin(), res.end());									// Reverse the str accumulated till now.
        return res;															// Return the reverse string.
    }
};