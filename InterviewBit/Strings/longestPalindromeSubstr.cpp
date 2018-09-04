/*
*
//**********************************************************Longest Palindromic Substring.***************************************************

Ghttps://www.interviewbit.com/problems/longest-palindromic-substring/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


aaaabaaaa


aaacbbcaaef



aabaaecbbbc




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).												// Can be improved to Linear Space Complexity. But complex to handle.
// This algorithm is Dynamic Programming based. We start from substrings of length 1 and reach length s.length(). As, len=1 substring are palin
// we set them as true in DP array. We then iter. over lengths and for each length, we iter. over all possible start indices. Based on palindrome
// nature of substrings of length len-1 and equality of chars at indices i,j, we decide whether substring from indices i to j is palindrome or 
// not? As, we have to return longest palindrome with smallest start index possible. We track longest palindrome encountered in a var. we also 
// store it's start, end indices. At the end we return the longset palindrome with smallest start index.







string Solution::longestPalindrome(string s) {
    if(s.length()<=1) return s;												// Base cases.
    vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));		// Tracks whether substrings b/w indices [i,j] are palindrome or not?
    
    for(int i=0;i<s.length();i++) dp[i][i]=true;							// As substrings of length 1 are palindrome.
    int maxm=1;																// Max. len of palindrome.
    int start=0,end=0;														// Start, end indices of longest palindrome encount. till now.
    for(int len=2;len<=s.length();len++){									// Iter. over all lengths.
        for(int i=0;i+len<=s.length();i++){									// Iter. over all possible start indices for curr. length.
            int j=i+len-1;													// End inex of substring under consideration.
            if((len==2 && s[i]==s[j]) || (len>2 && dp[i+1][j-1]==true && s[i]==s[j])){// If substring is palindrome.
                if(len>maxm){												// Try to udpate the max. length of palindrome encountered.
                    start=i;end=j;											// Store start, end indices of palindrome.
                    maxm=len;												// Stores length of palindrome.
                }
                dp[i][j]=true;												// Mark substring as palindrome.
            }
        }
    }
    return s.substr(start,end-start+1);										// Return the longest palindrome with smallest start index.
}
