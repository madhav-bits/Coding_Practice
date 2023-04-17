/*
*
//******************************************************2645. Minimum Additions to Make Valid String.******************************************************

https://leetcode.com/problems/minimum-additions-to-make-valid-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"b"
"aaa"
"abc"
"abcabcabc"
"cbacbacba"
"bacabacabcabbacaba"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, while iterating we compare curr. char with the expected char in that index as per requirement, if dont match we inc. res by 1 and we remain at same index,
// even if we remain curr. index, we will find a matching char in atmost 3 iter., if chars match we move to next index. After the iter. we still might have to add few chars to last char to make
// it valid. If the last char isn't 'c', we add the remaining char to make it valid. We return the #insertions made in the process.







class Solution {
public:
    int addMinimum(string s) {
        int res=0, j=0;
        string t="abc";																					// Expected chars patttern.
        for(int i=0;i<s.length();i++) {																	// Iter. over curr. string.
            if(s[i]!=t[j]) {																			// If curr. char isn't expected char.
                res++;																					// We inc. insertions count by 1.
                i--;																					// We remain at same index.
            }
            j=(j+1)%3;																					// Move to next expected char.
        }
        if(j!=0) res+=(3-j);																			// Checking if last char is part of valid set, else we calc. #insertions needed.
        return res;																						// Returning the #insertions needed to make it a valid string.
    }
};

