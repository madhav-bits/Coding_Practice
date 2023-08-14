/*
*
//*******************************************1781. Sum of Beauty of All Substrings.*******************************************

https://leetcode.com/problems/sum-of-beauty-of-all-substrings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aabcb"
"aabcbaa"
"kakgkftfnkotrpoerhrtohjijrejaojronbjrhjrohlagr"



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since the max./min frequencies in substr depends on the start, end indices of substr, only way for us it to form
// all substrs and calc. their max., min freq. For maxFreq, if we can update it if we observe freq. of any char>maxFreq. Where as for minFreq, we check that
// if the curr. char has freq. <= minFreq before inc. the freq. of curr. char. '<' comes in the case where a fresh/new char had occurred first time in the
// substr, then it's freq. will be <minFreq. '=' comes in the case any char with freq=minFreq being update in curr. index, as there might be other chars with 
// freq. =minFreq, we iter. over all chars track the minFreq. We now add maxFreq-minFreq to res, we move to next iter. and add next char. We repeat the process
// for all possible start indices and return the res at the end of process.






class Solution {
public:
    int beautySum(string s) {
        int res=0;
        int occur[26];
        for(int i=0;i<s.length();i++) {
            memset(occur, 0, sizeof(occur));
            int maxOccur=0, minOccur=INT_MAX;
            for(int j=i;j<s.length();j++) {
                if(++occur[s[j]-'a']>maxOccur) maxOccur=occur[s[j]-'a'];	// Updating the maxFreq of chars in the substr.
                if(minOccur>=occur[s[j]-'a']-1) {							// If prev. freq. of curr. char<=minFreq, minFreq might get updated.
                    minOccur=INT_MAX;
                    for(int i=0;i<26;i++) {									// We iter. over all chars and track minFreq.
                        if(occur[i]!=0 && occur[i]<minOccur) minOccur=occur[i];
                    }
                }
                res+=(maxOccur-minOccur);									// Adding beauty of curr. substr to res.
            }
        }        
        
        return res;															// Returning sum of beauty of all substrs.
    }
};

