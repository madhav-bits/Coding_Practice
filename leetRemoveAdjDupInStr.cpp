/*
*
//*****************************************1047. Remove All Adjacent Duplicates In String.*******************************************

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abbaca"
"azxxzy"
"abccbbbddcantkvvsascan"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We maintain res str in which we maintain chars which are remained after removing few dupli adj. chars as we iter. form left,
// when we are at 'i', we check if curr. char is equal to last char in res str if yes, we pop that char from res and as res last char and curr. char would be
// adj. chars after some deletions now. If they doesn't match we add curr. char to res. We return final res str at the end of iter.







class Solution {
public:
    string removeDuplicates(string s) {
        int i=0,j=1;
        while(j<s.length()) {												// Iter. over given string.
            if(i>=0 && s[i]==s[j]) i--;										// If last char of res and curr. char matches we pop it.
            else s[++i]=s[j];												// If they doesn't match or res is empty we add curr. char to res.
            j++;															// Moving iter. to right.
        }
        return s.substr(0,i+1);												// Returning the final res str.
    }
};

