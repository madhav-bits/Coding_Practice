/*
*
//****************************************1769. Minimum Number of Operations to Move All Balls to Each Box.****************************************

https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"110"
"001011"
"0101101000100101101001010"


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we keep track of #ones to the left of each index and the steps to move all prev. balls to prev. index with 
// the cnt of ones, which gives #moves to move all prev. balls to curr. box. We use the same logic and move iteration from right to left and update the
// result array at every step. We return the res array with minm. moves.






class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int>res(s.length(),0);										// Stores minm. moves to each index.
        int cnt=(s[0]=='1')?1:0;
        for(int i=1;i<s.length();i++){										// Calc. #moves to move all left balls to curr. index.
            res[i]=res[i-1]+cnt;
            if(s[i]=='1') cnt++;
        }
        cnt=(s.back()=='1')?1:0;
        int moves=0;
        for(int i=s.length()-2;i>=0;i--){									// Calc. #moves to move all right balls to curr. index.
            moves+=cnt;
            res[i]+=moves;
            if(s[i]=='1') cnt++;
        }
        return res;															// Returning array with minm. moves to move all boxes to each index.
    }
};