/*
*
//*******************************************1880. Check if Word Equals Summation of Two Words.*****************************************

https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"acb"
"cba"
"cdb"
"aaa"
"a"
"aab"
"aaa"
"a"
"aaaa"



// Time Complexity: O(n+m+l).												// n,m,l-length of three given strings.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+l).												// n,m,l-length of three given strings.
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate over three words and calculate their numerical equivalent and check whether sum of first, second words num.
// equivalent equals to that of targetWord's num. equivalent.







class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstVal=0, secondVal=0, targetVal=0;
        for(char &ch:firstWord) firstVal=firstVal*10+(ch-'a');				// Calc. numeircal equivalent of all strings.
        for(char &ch:secondWord) secondVal=secondVal*10+(ch-'a');
        for(char &ch:targetWord) targetVal=targetVal*10+(ch-'a');
        return ((firstVal+secondVal)==targetVal);							// Returning if sum of first two strings is equal to that of target word.
    }
};

