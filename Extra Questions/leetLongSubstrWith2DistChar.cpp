/*
*
//**********************************************159. Longest Substring with At Most Two Distinct Characters.***************************************

Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


""

"a"

"abbacccd"

"aabbccded"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window, HashMap based. At any instant, we will make sure that window follows the cdn mentioned in the question(It
// contais atmost 2 unique chars). If #unique chars >2, then we remove starting elem. of window, until one unique char is completely removed
// from window. Then, we try to update the max. len of window satisyfing given conditions.




class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length()==0) return 0;
        vector<int>pres(128,0);
        int count=0;
        int start=0,end=0,len=1;
        for(int i=0;i<s.length();i++){
            if(pres[s[i]-NULL]==0) count++;									// Tracks #Unique chars in window.
            pres[s[i]-NULL]++;												// Inc. count of curr. char.
            while(count>2){													// If #Unique chars>2, then remove one.
                pres[s[start]-NULL]--;										// Removing the last char form window.
                if(pres[s[start]-NULL]==0) count--;							// If a char is completely removed, then dec. count.
                start++;													// Inc. the index of start of window.
            }
            len=max(len,i-start+1);											// Calc. the window size, as it's cdn satisfied at any instant.
        }
        return len;															// Return the Max. len of window satisyfing given condition.
    }
};