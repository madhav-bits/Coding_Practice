/*
*
//*******************************************1930. Unique Length-3 Palindromic Subsequences.****************************************

https://leetcode.com/problems/unique-length-3-palindromic-subsequences/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aabca"
"adc"
"bbcbaba"
"awoijoiafgbkmemkdfmniaenropeefoiqo"



// Time Complexity: O(n*k)=O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k=O(n)).
// Space Complexity: O(1).	
// This algorithm is Prefix Sum+Map based. Here, we use an array to store palindromes which are already counted, since first and last char are same, we use 
// first two chars to rep the palindrome: s[0]*26+(s[1-'a). We iter. over array and store the #occur. of all chars in the string. We iter. over array and 
// and also keep tarck of prefixSum of chars occurred till 'i', we also substract left side chars from total count to reflect suffixSum of #occur of chars.
// For every index, we iter. over 26 chars and check if they are present on both sides of the curr. char, if yes we form rep of curr. palindrome and check if 
// it's already counted, if no we count it and mark it as counted and return total count at the end of iter.







class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res=0;
        bool palindrome[676];
        int occur[26], prefix[26];											// Keeps track of #occur of each char in string.
        memset(occur, 0, sizeof(occur));
        memset(prefix, 0, sizeof(occur));
        memset(palindrome, false, sizeof(palindrome));
        for(char&ch:s) occur[ch-'a']++;
        prefix[s[0]-'a']++;
        occur[s[0]-'a']--;
        for(int i=1;i<s.length()-1;i++) {									// Iter. over the string.
            // cout<<"index: "<<i<<endl;
            occur[s[i]-'a']--;												// To udpate the suffixSum of #occur of chars.
            for(char left=0;left<26;left++) {								// Iter. over all lower case chars.
                if(prefix[left]>0 && occur[left]>0 && palindrome[(left*26)+(s[i]-'a')]==false) {// If curr. first char occurred on both sides and rep not counted.
                    palindrome[(left*26)+(s[i]-'a')]=true;					// Marking as rep as counted.
                    // cout<<"palindrome rep: "<<char('a'+left)<<" and "<<s[i]<<endl;
                    res++;													// Increasing the 3 length uniq. palindrome subseq. count.
                }
            }
            prefix[s[i]-'a']++;												// Updating the prefixSum of #occur of chars.
        }
        return res;															// Returning total #3 length unique palindrome subsequences.
    }
};

