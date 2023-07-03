/*
*
//******************************************************1750. Minimum Length of String After Deleting Similar Ends.******************************************************

https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ca"
"cabaabac"
"aabbbaaabaaabbbaaa"
"aabbbcccaaaabbbbaaaccbbaa"
"aaaabbbccccbbbbbcbbaaaaa"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Two Pointer approach based. We use two pointers on both ends, in every iter. we remove same chars from both ends, we brake the loop
// if chars on both ends don't match or we delete all the chars.







class Solution {
public:
    int minimumLength(string s) {
        int start=0, close=s.length()-1;
        while(start<close && s[start]==s[close]) {							// Removing similar chars from both ends in every step.
            // cout<<"start: "<<start<<" and close: "<<close<<endl;
            int val=s[start];
            while(start<close && s[start]==val) start++;					// Removing the chars from the front.
            while(start<=close && s[close]==val) close--;					// Removing the chars from the back.
        }
        return close-start+1;												// Returning the length of the remaining string.
    }
};

