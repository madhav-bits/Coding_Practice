/*
*
//**************************************2825. Make String a Subsequence Using Cyclic Increments.***************************************

https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abc"
"ad"
"zc"
"ad"
"ab"
"d"
"aarljrdglkf"
"akre"



// Time Complexity: O(n+m).													//n-str1 length, m-str2 length.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-str1 length, m-str2 length.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, as we can change any inc. any char in str: 's' by 1 and form subseq: 't'. We use two ptrs on two strs and greedily
// try to match the earliest char in 's' with that of 't', such that we have more indices leftout to match the rem. chars/indices in 't'. While iter, for 
// every char in 's', we try to match, else we check if it matches if we inc. curr. char cyclically, if yes, we move to next char in 't', we move to next char 
// in 's' irrespective of matching, we stop iter. if we reach end of any of the strings. We return whether we are able to form all chars in 't'.







class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int len1=s.length(), len2=t.length();
        if(len2>len1) return false;											// Base condition.
        int j=0;
        for(int i=0;j<len2 && i<len1;i++) {									// We iter. over both strs.
            if(s[i]==t[j] || 												// We try to greedily match earliest char in 's' with the char in 't'.
               s[i]+1==t[j] || 
               (s[i]=='z' && t[j]=='a')) j++;								// If matched, we inc. the ptr in 't'.
        }
        return (j==len2);													// We return whether we are able to match all chars in 't'.
    }
};

