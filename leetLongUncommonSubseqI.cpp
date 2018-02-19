/*
*
//******************************************************521. Longest Uncommon Subsequence I.***********************************************

Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon 
subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon 
subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 
Note:

Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"abafsdfsd"
"cdcsdsv"

"bbcd"
"abcd"

"abcde"
"abgef"

"aaaaaaa"
"aaabgef"


// Time Complexity: O(n!).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).	
// Space Complexity: O(1).	
// This algorithm maintains the two least inc. subsequence of numbers, then compares the curr. scanning number with them, and decide if a triplet
// inc. subsequence can be formed or not. If the curr. vlaue > second min. number then triplet can be formed.


class Solution {
public:
    
    int findLen(string s1, string s2, int curr1, int curr2){
        if(curr1==s1.length())								// If end is reached, then the rem. part of other string is uncommon.
            return s2.length()-curr2;
        if(curr2== s2.length())
            return s1.length()-curr1;
        if(s1[curr1] !=s2[curr2])							// If curr. chars are not same, then all substring following this uncommon.
            return max(s1.length()-curr1,s2.length()-curr2);
        else												// If curr. chars are same, then look for uncommon in other combinations.
            return max(findLen(s1,s2,curr1+1,curr2), findLen(s1,s2,curr1,curr2+1));
    }

    
    int findLUSlength(string a, string b) {
        if(a==b) return -1;									// If both strings are equal, then return -1.
        int res=findLen(a,b,0,0);							// Calling the function to get Long Uncommon Subsequence.
        return res;
    }
};