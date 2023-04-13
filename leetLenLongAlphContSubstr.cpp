/*
*
//******************************************************2414. Length of the Longest Alphabetical Continuous Substring.******************************************************

https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abacaba"
"abcde"
"abcdghijkl"
"abedghijkl"
"abedghzijkl"
"abedghzijklabcdefg"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as we are trying to find longest substring of continuous alphabets, we check every adj. indices for continuous alphabets, if yes we inc. the length of
// curr. substring length else we reset it to 1. Before resetting the length to 1, we try to track and update the max substring length value and return it at the end of iter.







class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.length()==1) return 1;																		// Base condition.
        int len=1, res=1;
        for(int i=1;i<s.length();i++) {																	// Iter. over string.
            if(s[i]==s[i-1]+1) len++;																	// Check if adj. chars are continuous,if yes inc. the substr len by 1.
            else {																						// If adj. chars aren't continuous, we reset the length to 1.
                if(len>res) res=len;																	// Updating the max length of substring variable.
                len=1;	
            }
        }
        if(len>res) res=len;																			// Updating max length of substring based on last substring of the string.
        return res;																						// Returning the max length of continuous alphabets substring.
    }
};

