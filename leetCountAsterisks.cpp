/*
*
//******************************************************2315. Count Asterisks.******************************************************

https://leetcode.com/problems/count-asterisks/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"l|*e*et|c**o|*de|"
"iamprogrammer"
"yo|uar|e**|b|e***au|tifu|l"
"f|jr**dhd*|hj*rg|*d**gfh*|ufghfghhjtyk**dfgdfgsfg*|as|**gkh*dfgdgsf**|****|**fg"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we keep track of how many '|'s we had encountered till now, we only count those stars which occur after even numbered
// '|'s as prev. and next '|' don't form a pair and we can use it.







class Solution {
public:
    int countAsterisks(string s) {
        int res=0, occur=0;
        for(char&ch:s) {
            if(ch=='|') occur++;											// Updating #'|'s encountered.
            else if(ch=='*' && occur%2==0) res++;							// Counting stars b/w even followed by odd numbered '|'s.
        }
        return res;															// Returning total #excluded stars.
    }
};

