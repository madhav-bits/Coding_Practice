/*
*
//***********************************************************796. Rotate String.*****************************************************

We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it 
will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abefg", "fgabe"
"",""
"a","b"
"asfsadfasdf","asdfasdfsdf"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm takes the string removes the first index's char and places it at the end of the string, and checks whether newly formed string
// matches with the target string or not for LENGTH #times.



class Solution {
public:
    bool rotateString(string s, string t) {
        int len=s.length();
        string u="";
        for(int i=0;i<len;i++){											// Forming a new string LENGTH #times.
            s=s.substr(1,len-1)+s[0];									// Forming the transformed string.
            //cout<<"New string is: "<<s<<endl;
            if(s==t) return true;										// If new string is same as target string.
        }
        return false;													// If target str can't be obtained till now, then return false.
    }
};