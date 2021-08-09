/*
*
//**************************************************1525. Number of Good Ways to Split a String.***********************************************

https://leetcode.com/problems/number-of-good-ways-to-split-a-string/


*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"aacaba"
"abcd"
"aaaaa"
"acbadbaada"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since we are trying to get uniq. letters on each side of break. We try to get uniq. chars on right side 
// optimally. We first keep track of last Occurances of all chars and uniq. chars in the entire string. For every possible break, if the curr. char is 
// last occur. of that char, then right side's uniq. char count dec. by 1 from the total uniq. char count. of entire string. We keep left uniq. char
// cnt by using bool array, where we inc. cnt by 1 whenever we see a char whose index in bool array is false. If the uniqLeft and uniqRight are equal for 
// a break, we inc. the res by 1.







class Solution {
public:
    int numSplits(string s) {
        vector<int>lastOccur(26,-1);										// Tracks last occur. of chars in the string.
        int uniq=0;
        for(int i=0;i<s.length();i++){
            if(lastOccur[s[i]-'a']==-1) uniq++;								// Tracks the uniq. chars in the string.
            lastOccur[s[i]-'a']=i;
        }
        int res=0, uniqLeft=0, uniqRight=uniq;
        vector<bool>leftOccur(26, false);									// Tracks the uniq. chars on the left side.
        for(int i=0;i<s.length()-1;i++){
            if(lastOccur[s[i]-'a']==i) uniqRight--;							// If it's curr. char's last occur., then right side's uniq. cnt dec. by 1.
            if(leftOccur[s[i]-'a']==false) uniqLeft++;						// If it's curr. char's first occur, left side's uniq. cnt inc. by 1.
            leftOccur[s[i]-'a']=true;										// Marking that char has occured earlier.
            if(uniqRight==uniqLeft) res++;									// If left and right uniq. char cnt matches, we inc. res by 1.
        }
        return res;															// Returning the #good splits.
    }
};

