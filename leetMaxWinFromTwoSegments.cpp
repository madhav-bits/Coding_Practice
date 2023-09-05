/*
*
//************************************************2555. Maximize Win From Two Segments.**********************************************

https://leetcode.com/problems/maximize-win-from-two-segments/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,2,2,3,3,5]
2
[1,2,3,4]
0
[1,1,1,1,2,2,2,3,6,6,6,6,7,7,7,7,9,9,9,11,11,11,14,14,14,15,15,15,18,18,18,18,19,22,22,22,25,25,25,25,25]
5



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, we want the total length of two non-overlapping intervals whose values differ by <=k. We use DP to 
// track max length among valid intervals ending <=i in dp[i]. While iter. over the array, we maintain a valid  interval and try to maximize it's length as 
// much as possible, when at index 'i', our start index would be least possible start index, we calc. interval length and we max length ending before start
// from dp[start-1] and try to maximize sum of interval lengths and update res. We also update dp[i] with max of dp[i-1] and curr. interval length. We 
// return res at the end of iter.







class Solution {
public:
    int maximizeWin(vector<int>& v, int k) {
        int len=2*(k+1), res=0;
        if(len>=v.back()) return v.size();
        int maxCollect[v.size()], start=0;
        memset(maxCollect, 0, sizeof(maxCollect));
        for(int i=0;i<v.size();i++) {
            while(v[i]-v[start]>k) start++;									// Removing start indices to make it valid interval.
            int currTotal=i-start+1;										// Length of curr. interval.
            int prefix=(start==0)?0:maxCollect[start-1];					// Max interval length ending<start index.
            if(0ll+prefix+currTotal>res) res=prefix+currTotal;				// Update res with max sum of max lengths of two intervals.
            maxCollect[i]=currTotal;										// Update dp array.
            if(i>0 && maxCollect[i-1]>maxCollect[i]) maxCollect[i]=maxCollect[i-1];// Update dp array with max length of interval ending<=i index.
        }
        return res;															// Returning max sum of max lengths of two non-overlapping intervals.
    }
};

