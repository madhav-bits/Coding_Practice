/*
*
//**********************************************************44. Wildcard Matching.***************************************************

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcdefghi"
"a*e?h*"


""
""

""
"*"

"b a"
"b*"


"adceb"
"*a*b"


"a"
"a*"


"adceb"
"*a*dceb"


"ba"
"b*a"



// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Dynamic Programming based. We create a 2D array with string(s) as clmns and pattern(p) chars as rows. We assign an index
// [i,j]=1, iff all the all the chars till "i" in string and "j" in pattern matches. When we encounter chars(a-z), we compare them if they and
// prev. index [i-1,j-1] is 1, we have [i,j] has 1. If "?" is encountered, we check if prev. index [i-1,j-1] is 1. If "*" is encountered, we check
// prev. index[i-1,j-1] or it's earlier value in same row(as * overlaps multiple chars)[i,j-1] or earlier value in prev. row(as * also overlaps ""
// empty string)[i-1,j]. Thus, at the end of entire iteration, we check if [p.length(),s.length()] is 1 or not, if 1 return true else false.



// As curr. row's values depend only on prev. row, space complexity can be decreased by using (%2) notation and as a result only 2 rows 
// would suffice.



class Solution {
public:
    bool isMatch(string s, string p) {											// p is with special signs/pattern string.
        if(s.length()==0 && p.length()==0) return true;							// If both strings are "", return true.
        //if(s.length()==0) s=" ";
        vector<vector<int>>v(p.length()+1, vector<int>(s.length()+1,0));		// Creating 2D DP array.
        v[0][0]=1;																// Base case(empty strings are equal).
        int index=0;
        for(int i=1;i<v.size();i++){											// Iterating over the length of the string.
            if(p[i-1]=='*' &&  v[i-1][0]==1) v[i][0]=1;				// If single char("*") is given, then passing values as loop can't be entered.
            for(int j=1;j<v[0].size();j++){										// Iterating over the length of the pattern.
                //cout<<"Inside the for loop with i: "<<i<<"and j: "<<j<<endl;
                if( p[i-1]!='*' && p[i-1]!='?' && p[i-1]==s[j-1] && v[i-1][j-1]==1) v[i][j]=1;// If chars encountered, compare them.
                else if(p[i-1]=='?' && v[i-1][j-1]==1 && s[j-1]!=' ') v[i][j]=1;			// If '?' encount. check for prev. index [i-1,j-1].		
                else if(p[i-1]=='*' && (v[i-1][j-1]==1 || v[i][j-1]==1 || v[i-1][j]==1 )){	// If "*" encountered, check top, left, diagonally 
                    v[i][j]=1;													// above[i-1,j-1] if any of them is 1, then [i,j] is 1.		
                    if(v[i-1][j-1]==1) v[i][j-1]=1;								// This is when "*" is "", we pass values to next row-> "i+1" row
                } 																// without begin effected by "*".
            }
        }
        
        // for(auto nums: v){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        //cout<<"The value of last index is: "<<v[p.length()][s.length()]<<endl;
        return v[p.length()][s.length()]==1?true:false;							// If end index is 1,then pattern matches(true) if not return false.
    
    }
};