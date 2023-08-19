/*
*
//**********************************************2287. Rearrange Characters to Make Target String.********************************************

https://leetcode.com/problems/rearrange-characters-to-make-target-string/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ilovecodingonleetcode"
"code"
"abcba"
"abc"
"abbaccaddaeea"
"aaaaa"
"lkajlrjhaejoljthkneieupwojoaglkajrgllaksjoialfahlihahlfbwqoqwqjfkmscklnfbk"
"rjmhsoir"



// Time Complexity: O(n+m).													// n-given str length, m-target str length.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													// n-given str length, m-target str length.
// Space Complexity: O(1).	
// This algorithm is iteration based. We first get #occur. of each char in the given and target str. Then, we find how many sets of each uniq. char in target
// str can the given str provide by dividing #occur of char in given str by that of target str, and we track the minm #sets as we need all occuring char in 
// target to make a single copy of target str and we return the min. #sets at the end of iter.
// As we can rearrange chars, we need not bother about order but we are only concerned abt the #occur. of each char in both the strings.





class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int res=s.length();
        int occur[26], req[26];
        memset(occur, 0, sizeof(occur));
        memset(req, 0, sizeof(req));
        for(char&ch:s) occur[ch-'a']++;										// Counting #occur. of each char in target, given str.
        for(char&ch:target) req[ch-'a']++;
        for(int i=0;i<26;i++) {
            if(req[i]==0) continue;											// Skip chars which didn't occur in target str.
            if(occur[i]/req[i]<res) res=occur[i]/req[i];					// Calc. how many sets of target str can curr. char occur. support.
        }
        return res;															// Returning #sets/copies of target str that we can form from given str.
    }
};

