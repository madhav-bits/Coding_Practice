/*
*
//*******************************************1957. Delete Characters to Make Fancy String.*************************************************

https://leetcode.com/problems/delete-characters-to-make-fancy-string/.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"leeetcode"
"aab"
"aldskjaldrkhjlkfdjffffffffkljadflaasdf"
"aaaaaaaaaaaaaaaa"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. While iter. over orig. string, we keep on adding chars to res as long as 3 consec. chars aren't the same. If same we skip adding char to res,
// if diff. char found we reset the counter to 1 and add char to res. We return res at the end of iter.







class Solution {
public:
    string makeFancyString(string s) {
        int rep=1;
        string res=string(1,s[0]);
        for(int i=1;i<s.length();i++) {										// Iter. over orig. string.
            if(s[i]==s[i-1] ) {												// If consec. chars.
                if(++rep>=3) continue;										// If rep. value>=3, we skip adding curr. char to res.
            } else rep=1;													// If diff. consec. chars, we reset the count to 1.
            res+=s[i];														// Adding char in case of rep<3.
        }
        return res;															// Returning the resulting string after deletion of rep. chars.
    }
};

