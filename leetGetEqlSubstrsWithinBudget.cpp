/*
*
//*********************************************1208. Get Equal Substrings Within Budget.********************************************

https://leetcode.com/problems/get-equal-substrings-within-budget/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcd"
"bcdf"
3
"abcd"
"cdef"
3
"abcd"
"acde"
0



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. We maintain a window of indices and keep adding indices to the window until cost of changing chars in window 
// <=maxCost, once it is greater we can't extend the window anymore so we remove indices from the beginning until window cost becomes <=maxCost as the 
// substrings starting at these deleted indices can't be extended anymore. Once the window is valid, we try to track the max window size and continue to
// next index. We return max window size after the iter.







class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res=0, start=0, totalCost=0;
        for(int i=0;i<s.length();i++) {
            totalCost+=abs(s[i]-t[i]);										// Adding curr. index's cost to totalCost.
            while(totalCost>maxCost) {										// Pop start indices as long as window is invalid.
                totalCost-=abs(s[start]-t[start]);
                start++;
            }
            if(i-start+1>res) res=i-start+1;								// Track max window size of valid window.
        }
        return res;															// Returning the max window/substr size.
    }
};

