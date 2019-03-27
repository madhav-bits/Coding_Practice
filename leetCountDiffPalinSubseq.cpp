/*
*
//******************************************************730. Count Different Palindromic Subsequences.***********************************************

Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

A subsequence of a string S is obtained by deleting 0 or more characters from S.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

Example 1:
Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
Example 2:
Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
Note:

The length of S will be in the range [1, 1000].
Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ababaaa"

"aaaaafadfasdfasfbsfafaaaa"


"a"


""


"ababa"




// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, we calc. #palin. in increasing order of indices range lengths.While setting #palin. subseq in range
// [i,j] we take into account #palin. subseq in range [i+1, j-1] and whether both the chars s[i] and s[j] are matching or not? If s[i] and s[j] matches,
// there are 3 sub cases, we find one similar char. inside [i+1][j-1] then we form new palin. with curr. chars at indices[i,j] and palin. in substring
// [i+1, j-1] and [i,j] would form palin. of length 2. 
// If we don't have any similar chars in [i+1,j-1], then we form new palin. with palin. in substring [i+1,j-1] and add 2 palin. of index 'i' and also of
// index 'j'. 
// If we have atleast two similar chars in [i+1,j-1], then we form new palin. with pair of chars [i,j] and remove duplicates by deleting #palin. in 
// substring [first occur index+1(low), last occur. index-1(high)] of similar chars in curr. range of indices. As they form duplicates with [low, high ] 
// and [i,j]. If chars doesn't match, we return sum of #palin. in two diff. possibiities -#common palin. in the possibilities:  
// dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]
// We also make sure that values doesn't go out of bounds by using mod.
// The final answer would in bottom-right index.


// dp[i][j] indicates #palin. subseq. using chars in the index range.


// This link has very detailed explanation of the below algorithm:
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109507/Java-96ms-DP-Solution-with-Detailed-Explanation






class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int mod=1000000007;
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), 0));		// Init. dp array.
        for(int i=0;i<s.length();i++) dp[i][i]=1;							// Init. palin. of length 1.
        
        for(int len=2;len<=s.length();len++){
            for(int i=0;i<=s.length()-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){												// If curr. chars match.
                    int low=i+1, high=j-1;
                    while(s[low]!=s[i]) low++;								// Finding outermost similar chars inside the curr. range[i+1, j-1].
                    while(s[high]!=s[i]) high--;
                    if(low==high) dp[i][j]=dp[i+1][j-1]*2+1;				// Uses prev. palin. subseq and curr. pair of chars as palin.
                    else if(low>high) dp[i][j]=dp[i+1][j-1]*2+2;			// Uses prev. palin subseq and one of curr. chars, pair of curr. chars as palin.
                    else dp[i][j]=dp[i+1][j-1]*2-dp[low+1][high-1];			// Uses prev. palin. subseq and remove chars inside simi chars. leading to dup.
                }else{
                    dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  			// If no match, Calc. palin. with two possibilties and remove common subseq.  
                } 
                dp[i][j]=(dp[i][j]<0)?(dp[i][j]+mod):dp[i][j]%mod;			// Working on mod values.
            }
        }
        return dp[0][s.length()-1];											// Returning total #diff. palin. subseq.
    }
};


