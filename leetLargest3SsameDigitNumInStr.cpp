/*
*
//******************************************2264. Largest 3-Same-Digit Number in String.*******************************************

https://leetcode.com/problems/largest-3-same-digit-number-in-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"6777133339"
"4444"
"2300019"
"42352338"
"99383993988484434838838885493993"
"11223344332212244322"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. While iterating we count #consec. appearances of a number in the str. When we encounter a diff. char, we check #occur. 
// of prev. char, if it's >=3, we track max. of such char and reset the cnt to 1 for curr. char and continue the process. If by the end, we are not able to any
// char with atleast 3 consec. occur, we return empty string else we return a string of length 3 with the max char.







class Solution {
public:
    string largestGoodInteger(string s) {	
        char ch='#';														// Tracks max char which had occurred consecutively 3 times atleast.
        int cnt=1;
        for(int i=1;i<=s.length();i++) {
            if(i==s.length() || s[i]!=s[i-1]) {								// If curr. char is diff from prev. char.
                if(cnt>=3 && s[i-1]>ch) ch=s[i-1];							// If #occur of prev. char is>=3, we track max of such chars.
                cnt=1;														// We rest the count to 1 for curr. char.
            } else cnt++;													// If curr=prev. char, we inc. cnt by 1.
        }
        return (ch=='#')?"":string(3,ch);									// Returning a str of length 3 with max char if we find any else return empty str.
    }
};

