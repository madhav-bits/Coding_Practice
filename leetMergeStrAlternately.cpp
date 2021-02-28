/*
*
//******************************************************1768. Merge Strings Alternately.***********************************************

https://leetcode.com/problems/merge-strings-alternately/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"abc"
"pqr"
"ab"
"asdfa"



// Time Complexity: O(n+m).  
// Space Complexity: O(n+m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).
// Space Complexity: O(n+m).	
// This algorithm is iteration based. Until the indices are present in both the stirngs, we add the chars from both the strings alternately. We append
// rest of chars from longest string to res string and return the res string.








class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0;
        while(i<word1.length() && i<word2.length()){
            res+=word1[i];
            res+=word2[i];
            i++;
        }
        
        while(i<word1.length()) res+=word1[i++];
        
        while(i<word2.length()) res+=word2[i++];
        return res;
    }
};