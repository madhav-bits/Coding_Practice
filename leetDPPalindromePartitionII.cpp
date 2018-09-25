/*
*
//******************************************************132. Palindrome Partitioning II.***********************************************


Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"aab"



"aabaaccdeaegh"


"aabaaccdeafaefasdfegh"



"aaeaa"


""



"ab"



"abbaabac"


"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"


// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, we first build the Palindrome DP lookup table. Later, we try to build the palindrome split
// substr from previously built palindrome substr, same as the palindrome DP building. Since, min. #palin. in substr, depends on blocks of 
// substr in that substr, we iter. through every iter. and break substr into two pieces, get the min. sum of those substr. Overall this takes
// O(n^3) time. 



// This sln is Classic Solution in O(n^3) complexity. It passes all the cases except the last lengthy test case(Where it has thrown TLE).





class Solution {
public:
    int minCut(string s) {
        if(s.length()==0) return -1;
        vector<vector<bool>>dp(s.length(), vector<bool>(s.length(), false));
        vector<vector<int>>cuts(s.length(), vector<int>(s.length(), s.length()));
        for(int i=0;i<s.length();i++) cuts[i][i]=0;							// Base cases(#cuts for substr length 1 is 0).
		
		for(int i=0;i<s.length();i++) dp[i][i]=true;						
        for(int len=2;len<=s.length();len++){								// Building Palindrome lookup table.
            for(int i=0;i<=s.length()-len;i++){
                if(len==2 && s[i]==s[i+1]) dp[i][i+1]=true;
                else if(len>2 && s[i]==s[i+len-1] && dp[i+1][i+len-2]==true) dp[i][i+len-1]=true;
            }
        }
        // for(auto nums:dp){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        if(dp[0][s.length()-1]==true) return 0;
        int res=s.length();
        for(int len=2;len<=s.length();len++){								// Building #palin. in a substr DP table. 
            for(int i=0;i<=s.length()-len;i++){								// Iter. through all starts for that length of substr.
                int close=i+len-1;											// Last index in this substring.
                if(dp[i][close]==true) cuts[i][close]=0;					// If the entire substr is Palindrome, then assign 0 cuts.
                for(int j=i;j<close;j++){									// Iter. through all indices in curr. substr.
                    cuts[i][close]=min(cuts[i][close], 1+cuts[i][j]+cuts[j+1][close]);// Min. cuts from the substr pieces count.
                }
            }
        }
        
        
        // for(auto nums:cuts){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        
        return cuts[0][s.length()-1];										// Returning min. count for entire string.
        
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. Here, we build Palindrome lookup, #Palin. lookup DP at the same time. The whole concept is same 
// as above, but small yet crucial observation. The iter. for breaking substr into two parts, where two parts comprises of palin. In these 
// both parts, they end with palin. We can merge two innermost iter. from above algo. into two one. In one loop, we iter. over closing of
// substr, in one loop, we iter. over start of last palin. and try to minimize cuts in that substr.As, the last one is #palin, we add+1 to cuts[i-1].


// This link has some more explanation for the below algo.
// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42213/Easiest-Java-DP-Solution-(97.36)








class Solution {
public:
    int minCut(string s) {
        vector<int>cuts(s.length(),s.length());								// Tracks #cuts till index 'i'.
        vector<vector<bool>>dp(s.length(), vector<bool>(s.length(), false));// Palindrome substr Dp lookup table.
        for(int i=0;i<s.length();i++) dp[i][i]=true;						// Init. substr of length 1.
        
        for(int j=0;j<s.length();j++){										// Iter. over all indices of string.
            for(int i=0;i<=j;i++){											// Iter. over all indices of start of last palin.
                if(s[i]==s[j] &&((i+1>j-1) || dp[i+1][j-1]==true)){			// If last substr is palin.
                    dp[i][j]=true;											// Store as palin.
                    if(i==0) cuts[j]=0;										// If the entire substr is palin. assign 0 cuts.
                    else cuts[j]=min(cuts[j], cuts[i-1]+1);					// Else, assign cuts till index 'i-1'+1 and minimize cuts var.
                }
            }
        }
        return cuts.back();													// Returning min. cuts for entire string.
        
    }
};