/*
*
//******************************************************2379. Minimum Recolors to Get K Consecutive Black Blocks.******************************************************

https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"WBBWWBBWBW"
7
"WBWBBBW"
2
"WBWBWWWBBWWBBBWWBBWBWBW"
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. As we are trying to get K consec. blocks of Black blocks. We maintain a window of target size, we count #whites
// at any point of time, which is the #oper. needed to convert curr. window to all black blocks. We return the minm. value of #whites observed during iter.







class Solution {
public:
    int minimumRecolors(string s, int k) {
        int res=k, req=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='W') req++;											// If curr. is white block, we inc. #oper. required to get all black blocks.
            if(i>=k && s[i-k]=='W') req--;									// If removing index is White, we dec. #oper. required.
            if(i>=k-1 && req<res) res=req;									// Track the least #oper. required to get an all black K size window.
        }
        return res;															// Returing the minm. #oper. required to get a K size window of all black blocks.
    }
};

