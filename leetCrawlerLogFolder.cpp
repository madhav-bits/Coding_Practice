/*
*
//******************************************************1598. Crawler Log Folder.***************************************************


https://leetcode.com/problems/crawler-log-folder/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


Worked with the test cases provided with question.


// Time Complexity: O(n*m).													// n-#operations. m-length of the log string.  
// Space Complexity: O(1).													// Constant space.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n-#operations. m-length of the log string. 
// Space Complexity: O(1).													// Constant space.
// This algorithm is comparison based. Here, for every log we compare them with possible logs, we keep track of depth of the curr. folder
// from the main folder by the var.(steps). If we encounter "../" we dec. the count, if we encounter any string other than "./" we inc.
// the count. At the end,we return the cnt, as these are the steps we have to take to go to main folder.
// While dec. the count, we also ensure this is >=0, as the move to parent oper. won't work when in main directory.







class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps=0;														// Tracks the recursion depth of the directory we are in.
        for(auto&str: logs){
            if(str=="../") steps=max(0, steps-1);							// Dec. cnt as we go to parent folder.
            else if(str!="./") steps++;										// We go to child folder.
        }
        return steps;														// Return the depth of the curr. folder/steps to go back.
    }
};