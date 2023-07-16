/*
*
//******************************************************2370. Longest Ideal Subsequence.******************************************************

https://leetcode.com/problems/longest-ideal-subsequence/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"acfgbd"
2
"abcd"
3
"harlkarhlah"
4
"ljhadrojlkjaerojoladjhaldr"
5



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. Here, as we are trying to form subsequence where adj. chars have <=k abs diff, we use a dp array where dp[i]
// shows longest subsequence with 'a'+i char being the last char until now. So, when we are at index 'i' with char: 'ch', we iter. over 'ch-k' to 'ch+k' chars
// in dp array and add +1 to their length and try to maximize the subsequence length with curr. char being last char and update dp[ch-'a']. At the end of iter.
// we get the max length of subseq by iter. over dp array and returning it.
 






class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        for(int i=0;i<s.length();i++) {
            int j=s[i]-'a', maxm=0;
            for(int l=max(0, j-k);l<=min(25, j+k);l++) {					// Checking all chars which are within abs. diff dist from s[i]
                maxm=max(maxm, dp[l]+1);									// Adding curr. char to those prev. chars, so we add +1 and maximize subseq. ending with curr. char.
            }
            dp[j]=maxm;														// Assigning the max length to curr. char's index.
        }
        
        int res=*max_element(dp.begin(), dp.end());							
        return res;															// Returning the max. length of subsequence which satisfies the conditions.
    }
};


