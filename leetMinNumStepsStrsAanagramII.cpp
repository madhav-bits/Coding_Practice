/*
*
//****************************************2186. Minimum Number of Steps to Make Two Strings Anagram II.**************************************

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"leetcode"
"coats"
"night"
"thing"
"lkjhaljhklmlgjoainhprtijaoh"
"jlkjhaojlsjftaproaetpjego"



// Time Complexity: O(n+m).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we as we can add chars to any of the strings, we calc. diff. in occur of each of the lowercase chars. If 
// it's occur. is greater in s, the resulting occur[i]>0 else if would be neg. In case of pos. occur[i], we have to add chars in 't' else we add chars in 's'.
// Thus, we add any deviation from zero towards res and return it.







class Solution {
public:
    int minSteps(string s, string t) {
        int res=0;
        int occur[26];
        memset(occur, 0, sizeof(occur));
        for(char&ch:s) occur[ch-'a']++;										// Tracking #occur. of chars in s.
        for(char&ch:t) occur[ch-'a']--;										// Tracking #occur. of chars in t.
        for(int i=0;i<26;i++) {
            if(occur[i]>=0) res+=occur[i];									// If char occured more in 's', we add chars in 't' to match occur in 's'.
            else res-=occur[i];												// If char occured more in 't', we add chars in 's' to match occur in 't'.
        }
        return res;															// Returning minm. #chars added to make two strings anagrams.
    }
};

