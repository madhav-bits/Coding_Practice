/*
*
//******************************************************2730. Find the Longest Semi-Repetitive Substring.******************************************************

https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"52233"
"5494"
"1111111"
"111"
"28284838832858383"
"12345654321"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we are trying to get max. length of substring where at max one consec. pair of same value is allowed. So, we 
// iter. and check for consec. same char pairs, if they are pair, we inc. the pairs count. If the #pairs>1, we forward the window's start until #pairs==1, once
// we satisfy the condition, we try to maximize the length of the substring that satisfies the condition and return it at the end of iter.







class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res=0, pairs=0,start=0;
        for(int i=0;i<s.length();i++) {
            if(i>0 && s[i]==s[i-1]) pairs++;								// Tracks #pairs in the window.
            while(pairs>1) {												// If the #pairs>1, we forward start of window until pairs<=1.
                if(s[start]==s[start+1]) pairs--;							// As chars match, we dec. pairs count.
                start++;													// Forwarding the start of the window.
            }
            if(i-start+1>res) res=i-start+1;								// Tracking the max. length of the window.
        }
        
        return res;															// Returning the max. length of the window.
    }
};

