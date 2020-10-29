/*
*
//*************************************1347. Minimum Number of Steps to Make Two Strings Anagram.***************************************

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on test cases provided with the question.
"bab"
"aba"
"leetcode"
"practice"
"anagram"
"manager"
"xxyyzz"
"xxyyzz"


// Time Complexity: O(n+m).  
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).
// Space Complexity: O(k).	
// This algorithm is observation based. Here, we use an array to store the #occur. of chars in both the strings, if char occured in 
// 's' we inc. the count and dec. the count if char occured in 't'. As we wanted to know count of all chars in 's' which are not in 't'
// and modify them to the extra chars in 't', then both strings would be anagrams.







class Solution {
public:
    int minSteps(string s, string t) {
        int res=0;
        vector<int>occur(26,0);												// Tracks #occur. of each char.
        for(auto ch:s) occur[ch-'a']++;										// Inc. count for 's' chars.
        for(auto ch:t) occur[ch-'a']--;										// Dec. count for 't' chars.
        for(auto num:occur) if(num>0) res+=abs(num);						// Counting extra chars in 's' to connvert to extras in 't'.
        return res;															// Return the #moves needed.
    }
};