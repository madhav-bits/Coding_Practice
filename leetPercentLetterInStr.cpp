/*
*
//******************************************************2278. Percentage of Letter in String.******************************************************

https://leetcode.com/problems/percentage-of-letter-in-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"foobar"
"o"
"jjjj"
"k"
"aaaa"
"a"
"abaaabb"
"a"
"aaaabbb"
"b"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We count number of times desired char occurred in the given string. As we are trying to get whole number percentages,
// the nums would be in range [0,100], we get the percent by dividing #occur of char by total length of string. For us to get whole rounded down percent, we 
// can multiply the #occur. by 100 and divide by total length, which gives rounded down percent in [0,100].







class Solution {
public:
    int percentageLetter(string s, char letter) {
        int occur=0;
        for(char&ch:s) {
            if(ch==letter) occur++;											// Calc. #occur of given char in str.
        }
        occur*=100;															// Multiply with 100 to get rounded whole percent.
        return occur/s.length();											// Returning the rounded down whole number percentage.
    }
};

