/*
*
//*************************************1433. Check If a String Can Break Another String.*************************************

https://leetcode.com/problems/check-if-a-string-can-break-another-string/description/



Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or 
vice-versa (in other words s2 can break s1).

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

 

Example 1:

Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
Example 2:

Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: 
"acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 
and vice-versa.
Example 3:

Input: s1 = "leetcodee", s2 = "interview"
Output: true
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"abc"
"xya"

"leetcodee"
"interview"

"abe"
"acd"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, a strings breaks another if it's some perm. is greater than other str. We can cnt,
// #occurrences of each char in both strs and store them in diff. arrays. We iter. over the arrays parallelly, at every index, the 
// cnt of all values till then of one array has to be >= or <=, and the sign has to be same throughout, so we maintain another var,
// which tracks the sign of comparision, initially it is set to 0, indicating they are equal. At every index, if cnt is same, we skip
// it. If it is not equal, we check what was sign till then if it is other way around, we return false. If it is equal to 0, we assign
// the sign now. If we haven't faced any scenarios where the signs changed over indices, we return true. 








class Solution {
public:
    bool checkIfCanBreak(string s, string t) {
        
        vector<int>occur(26,0), occur2(26,0);								// Tracks #occurrences of each char.
        for(char ch:s) occur[ch-'a']++;										// Count chars of first array.
        for(char ch:t) occur2[ch-'a']++;
        int totalS=0, totalT=0;												// Tracks Cumul. sum of chars count in strings.
        int more=0;															// Tracks the sign of comparision, init to 0 as it's equal.
        for(int i=0;i<26;i++){												// Iter. over all chars.
            totalS+=occur[i];												// Cumul. #occurrences of chars.
            totalT+=occur2[i];
            if(totalS==totalT) continue;									// If cnt is same, skip it.
            if(more==1 && totalS>totalT) return false;						// If it is more but prev. sign was diff., we return false.
            if(more==-1 && totalT>totalS) return false;						// If it is less but prev. sign was diff., we return false.
            if(totalS>totalT) more=-1;										// We assign sign accordingly, we also reassign sometimes.
            else more=1;
        }
        return true;														// Return true if we can break str.
    }
};

