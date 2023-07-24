/*
*
//******************************************************2483. Minimum Penalty for a Shop.******************************************************

https://leetcode.com/problems/minimum-penalty-for-a-shop/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"YYNY"
"NNNNN"
"YYYY"
"YNYNYYYYNYNYNNYNYNYNNYNYNYN"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is PrefixSum/SuffixSum based. We do suffixSum of all 'Y' whose index>= closing index, which initially is 0. While iter. we also keep track
// of #'N' s encountrered along the way till index 'i' and also keep substracting 'Y's from suffixYs. At every index, we add prefixNo+suffixYes and try to 
// minimze their sum and store it's index of occurrence. We return index at the end of iter.







class Solution {
public:
    int bestClosingTime(string s) {
        int res=-1,minPenalty=INT_MAX, penalty=0;
        int suffixYes=0, prefixNo=0;
        for(char&ch:s) if(ch=='Y') suffixYes++;								// Counting all 'Y's whose indices >= curr. index: '0'.
        for(int i=0;i<s.length();i++) {
            penalty=prefixNo+suffixYes;										// Calc. penalty if store closed at index 'i'.
            if(penalty<minPenalty) {										// Tracking minm. penalty and it's index.
                res=i;
                minPenalty=penalty;
            }
            if(s[i]=='N') prefixNo++;										// Inc. prefixN cnt by 1, as curr. index would be part of open index in next iter.
            else suffixYes--;												// Dec. suffixY cnt by 1, as curr. index would be part of open index in next iter.
        }
        if(prefixNo+suffixYes<minPenalty) res=s.length();					// This is for index: 's.length()' instance.
        return res;															// Returning the earliest index where minm. penalty is incurred.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This algorithm is Observation based. This solution works on relative penalty from the initial psn, we assume that the penalty at index: '0' is zero and 
// we make this minPenalty and store this index, as we move to next index, index: '0' moves from close to open index, this would be only change from the early
// instance, so contribution from rest all indices towards penalty would still be the same after moving close index by 1. So, if curr. index has 'Y', that means
// 'Y' in close becomes 'Y' in open index, 'Y' in close index contributes to penalty but it wont in open index, so we dec. penalty by 1, reverse would be the
// case for 'N' from close to open index, where the penalty would increase by 1. When we move to next iter. we use this updated penalty score and track the 
// minm penalty score and it's index and return it at the end of iter.


// We can use this technique for most of the prefix/+suffix sum related questions where contribution of each index remains independent from other indices and
// we have to return minIndex/maxIndex.





class Solution {
public:
    int bestClosingTime(string s) {
        int res=0,minPenalty=0, penalty=0;									// Set '0' penalty for '0' index.
        for(int i=0;i<s.length();i++) {
            penalty+=(s[i]=='Y')?-1:1;										// As 'i' moves from close to open index, we change penalty contribution acc.
            if(penalty<minPenalty) {										// Tracking min relative penalty and it's index.
                res=i+1;
                minPenalty=penalty;
            }
        }
        return res;															// Returning the earliest index where minm relative penalty has incurred.
    }
};



