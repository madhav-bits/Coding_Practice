/*
*
//**********************************************************72. Edit Distance.***************************************************

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"horse"
"ros"


"hrse"
"rose"



"horse"
""


""
"ros"

""
""



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Dynamic Progamming based. We form a DP array with s2.length()+1 rows an s1.length()+1 clmns. A value at dp[i][j] indicate
// #changes to be made to convert given string s2 of length "j" to target string of length "i". If s2[i]==s1[j], then the number of changes is
// same as dp[i-1[j-1], if not equal, then we take minimal of dp[i-1[j-1], dp[i-1][j], dp[i][j-1] and one to get the updated value of dp[i][j]
// we take min. cause taking value from dp[i-1[j-1] indicate we would be REPLACING the curr. char in given str. to suit the target string's
// curr. char.
// Taking value form dp[i-1][j] means a new char. s2[j-1] would be INSERTED to given str. to match the target str.
// Taking value from dp[i][j-1] means the curr. char in target string is DELETED to match the target str.






class Solution {
public:
    int minDistance(string s1, string s2) {
        vector<vector<int>>dp(s2.length()+1,vector<int>(s1.length()+1,0));			// Creating a dp array.
        
        for(int i=0;i<=s2.length();i++){
            for(int j=0;j<=s1.length();j++){
                if(i==0) dp[i][j]=j;												// Initializing base cases.	
                else if(j==0) dp[i][j]=i;
                else if(s2[i-1]!=s1[j-1]) {											// If curr. chars doesn't match.
                    int minm=min(dp[i-1][j-1], dp[i-1][j]);							// Getting the minm. of three previous adj. combinations.
                    dp[i][j]=min(minm, dp[i][j-1])+1;
                }
                else dp[i][j]=dp[i-1][j-1];											// If curr. chars matches, taking #changes form [i-1][j-1].
            }
        }
        
        // for(int i=0;i<=s2.length();i++){
        //     for(int j=0;j<=s1.length();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
            
        // cout<<"The answer is: "<<dp[s2.length()][s1.length()]<<endl;
        return dp[s2.length()][s1.length()];										// Returning the total number of changes.
    }
};