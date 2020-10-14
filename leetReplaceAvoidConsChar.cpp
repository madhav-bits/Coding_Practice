/*
*
//***************************1576. Replace All ?'s to Avoid Consecutive Repeating Characters.*******************************

https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"?zs"
"??yw?ipkj?"
"??bw?ipkj?"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration and observation based. Here, whenever we encounter '?', we assign the value prev. char+1,
// or 'a' if prev. char is 'z'. If curr. char(not '?') and prev.char are equal, then it's that orig. prev. char(?) had been
// replaced with same as curr. char, so we will inc. pre. char by 1 or replace with 'a', if it is 'z'. Thus, consec.
// chars won't be the same.








class Solution {
public:
    string modifyString(string s) {
        if(s[0]=='?') s[0]='a';
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) s[i-1]=(s[i-1]=='z'?'a':s[i-1]+1);	// If repl. prev. char '?' and curr. are same, inc. prev. char by 1.
            if(s[i]=='?') s[i]=(s[i-1]=='z'?'a':s[i-1]+1);					// If '?', replace it with prev. char+1.
        }
        return s;															// Return the modified string.
    }
};