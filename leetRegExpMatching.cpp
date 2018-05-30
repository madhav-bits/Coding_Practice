/*
*
//******************************************************10. Regular Expression Matching.***********************************************

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aab"
"c*a*b"


"mississippi"
"mis*is*ip*."


"abcd"
".*c*cd"


"adceb"
"a*a*dceb"

"ba"
"**ba"

"cba"
"**ba"




"abcd"
"ab*c*c*d*e*"

"mississippi"
"mis*is*p*."

"abbbbcd"
"a*x*y*z*a*b*ca*d*f*"

"abbbbcd"
"a*x*y*z*a*b*ca*d*f*"

"a"
"ab*"




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based. We convert this problem * speaks of the previous char to it to other where c* will be replaced by
// C, which indicates one or more "c"s, also ".*" is replaced by "*", which means one or more any chars. 

// In the dp when we encounter small chars we compare curr. indices and [i-1,j-1] and assign values accordingly. If '.' we assign true and move 
// ahead. When "*" encountered, we check for [i-1,j-1]/[i,j-1]/[i-1,j] to be 1 and assign true to curr. index. If large chars are encoun., we check
// for same indices as above, but we also check for equality of curr. indices in both strings/If same clmn prev. row value is 1, then assign this 1.







class Solution {
public:
    bool isMatch(string s, string p) {
        string t="";
        for(int i=0;i<p.length();i++){														// Converting prob. to new stmnt with new meanings.
            if(p[i]=='*'){
                int len=t.length();
                if(t[len-1]>=97 && t[len-1]<=122) t[len-1]-=32;								// small chars followed by "*" replaced by big char.
                else if(t[len-1]=='.') t[len-1]='*';										// ".*" replaced with "*"
            }
            else t+=p[i];
        }
        //cout<<"new string is: "<<t<<endl;
        vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1, 0));					// Declaring DP vector.
        dp[0][0]=1;																			// Base case, when both strings are empty.
        int begin=1;
        for(int i=1;i<dp.size();i++){
            if(((t[i-1]>=65 && t[i-1]<=90) || t[i-1]=='*') && dp[i-1][begin-1]==1) dp[i][begin-1]=1;
            for(int j=begin;j<dp[0].size();j++){
                //cout<<"Inside the inner loop with i: "<<i<<" and j: "<<j<<" and s char: "<<s[j-1]<<" and p char: "<<t[i-1]<<endl;
                // Hanldes small alphabets.
                if(t[i-1]>=97 && t[i-1]<=122 && t[i-1]==s[j-1] && dp[i-1][j-1]==1){	// If small chars are encontered, then compare curr. indices.
                    //cout<<"Inside the small chars."<<endl;
                    dp[i][j]=1;    
                } 
                // Handles '.' case.
                else if(t[i-1]=='.' && dp[i-1][j-1]==1) dp[i][j]=1;				// If "." encount., if diago. val=1, then curr. =1.
                // Handles "Block chars.
                else if(t[i-1]=='*'&& (dp[i-1][j-1]==1 || dp[i][j-1] || dp[i-1][j])){// If "*" encountered, check top, left, diagonally
                    dp[i][j]=1;													// if anyone is 1, curr. val=1.
                    if(dp[i-1][j-1]==1) dp[i][j-1]=1;							// This is when curr. index is taken as empty string.
                }
                // Handles Large alphabets.
                else if(t[i-1]>=65 && t[i-1]<=90 && ((dp[i-1][j-1]==1) || dp[i][j-1] || dp[i-1][j])){// If Large encount, check top, left, diagonally
                    //cout<<"Inside the large chars."<<endl;					// if anyone is 1, we check curr. index/ prev. row is 1, then val=1.
                    if(t[i-1]+32==s[j-1] || dp[i-1][j]==1) dp[i][j]=1;
                    if(dp[i-1][j-1]==1) dp[i][j-1]=1;							// I guess this line isn't needed, it's convered above this loop.
                }
                
            }
            if((t[i-1]>=97 && t[i-1]<=122) || t[i-1]=='.' ) begin++;			// If special repeating symbols not encount., then inc. index.
        }
        
        // for(auto nums: dp){													// Printing values in DP vector.
        //     for(auto num:nums)	
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        
        //cout<<"The result is: "<<dp[t.length()][s.length()]<<endl;
        return dp[t.length()][s.length()]==1?true:false;						// Returning the result.
        
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is HashMap based, but slightly simpler one. When "*" encountered compare chars from prev. index, we also try to pass values from 
// indices prior to curr. repeating char[i-2,j]. If others encountered, we compare chars in curr. index. 







class Solution {
public:
    bool isMatch(string s, string t) {
        
        vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1, 0));	// Declaring the DP vector.
        dp[0][0]=1;															// Base case, when both strings are empty.
        for(int i=1;i<dp.size();i++){
            if(t[i-1]=='*') dp[i][0]=dp[i-2][0];// We pass values through repeating chars to next indices/rows, when single char. is given in "s".
            for(int j=1;j<dp[0].size();j++){
                if(t[i-1]=='*'){										// If "*" encoun. then try to pass values from prev. char[i-2]/comp.-
                    if(dp[i-2][j]==1 || (dp[i][j-1]==1 && (t[i-2]==s[j-1] || t[i-2]=='.'))) dp[i][j]=1;// curr. chars.
                }
                else{													// Other chars encountered, we compare chars in curr. index.
                    if(dp[i-1][j-1]==1 && (t[i-1]==s[j-1] || t[i-1]=='.')) dp[i][j]=1;
                }
                
            }
        }
        
        //cout<<"The result is: "<<dp[t.length()][s.length()]<<endl;
        return dp[t.length()][s.length()]==1?true:false;				// Returning the result.
        
    }
};