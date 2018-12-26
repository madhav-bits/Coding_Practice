/*
*
//**************************************************************664. Strange Printer.*****************************************************

There is a strange printer with the following two special requirements:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
Hint: Length of the given string will not exceed 100.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



afjaoiefasefasnefaosiefn


aabbccaabb

abaaaabaacbbabba



""

a


aaa


abcbacghdca


abcbacdca





// Time Complexity: O(n^3).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. HERE, THE MAIN LOGIC IS THAT IF A SUBSTRING FROM INDEX I TO J IN CONSIDERED, IF s[i] AND s[j] ARE
// EQUAL, THEY BOTH CAN BE PRINTED IN SINGLE MOVE. While calculating dp[i][j] we iterate over all possible breaks 'k' from 'i+1' to 'j-1' and 
// find which of those combinations will lead to curr. substring with least #moves. We iter. from substrings of len=2 to len=string's length. For 
// each len. we iterate over all possible starts, for each start, end pair, we iter. over all possible breaks and choose the best break leading to 
// curr. substring. At the end of all iterations, we return the min. #moves to get entire string.




// dp[i][j] is the min. #turns taken to print substring from 'i' to 'j' index.



class Solution {
public:
    int strangePrinter(string s) {
        if(s.length()==0) return 0;											// Base case.
        vector<vector<int>>dp(s.length(), vector<int>(s.length(), s.length()));	// Declaring an DP array.
        for(int i=0;i<s.length();i++) dp[i][i]=1;							// Init. base cases of substrings of length 1.
        
        for(int len=2;len<=s.length();len++){								// Iter. over substrings of len=2 to string's length.
            for(int i=0;i+len<=s.length();i++){								// Iter over all possible starts for each length.
                for(int j=i+1;j<i+len;j++){									// Iter. over all possible breaks for each len, start, end triplet.
                    dp[i][i+len-1]=min(dp[i][i+len-1], dp[i][j-1]+dp[j][i+len-1]);// Accept the break which leads to min. #moves.
                }
                if(s[i]==s[i+len-1]) dp[i][i+len-1]--;						// If last and first char are equal, remove 1 as both can be printed in 
																			// single move.
            }
            
        }
        // for(auto nums: dp){
        //     for(auto num:nums)
        //         cout<<num<<"\t";
        //     cout<<endl;
        // }
        return dp[0][s.length()-1];											// Returning min. #moves to get target string.
    }
};