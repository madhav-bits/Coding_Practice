/*
*
//************************************************************161. One Edit Distance.*****************************************************

Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ab"
"acb"


"ab"
"abc"

"abc"
"ab"


"abc"
"abd"


"abcefg"
"abdefg"


"abcefg"
"abefg"


"abcd"
"abcd"


""
""



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, we first compare the lengths of both strs and decide what move would be needed to make their lengths equal.
// In the iteration, when we find a mismatch, we make a change(move) as found, and check whether rest substr are equal or not? If we didn't find any
// mismatches by the end of shorter string, then the mismatch would be at the last char. of other str(As strs differ by 1->len). If both strs are 
// equal return false.








class Solution {
public:
    
    bool isOneEditDistance(string s, string t) {
        int len1=s.length(), len2=t.length();						// Calc. lengths of both strs.
        if(s==t) return false;										// If two strings are equal, return false.
        int move=2;
        if(s.length()==t.length()) move=2;                          //Replacing char.
        else if(s.length()==t.length()-1) move=1;                   // Add one char to "s".
        else if(s.length()==t.length()+1) move=0;                   // Remove one char from "s".
        else return false;											// No moves possible resulting in same length, return false.
        int i=0;
        for(;i<s.length() && i<t.length();i++){
            if(s[i]!=t[i]){											// When chars doesn't match.
                if(move==2){                                        // Replacing char.
                    // cout<<"Replacing char: "<<endl;
                    s[i]=t[i];
                    return s.substr(i+1)==t.substr(i+1);			// Check whether rest substrings are equal.
                }
                else if(move==1){                                   // Add one char to "s".
                    // cout<<"Adding char: "<<endl;
                    s.insert(i,t.substr(i,1));
                    return s.substr(i+1)==t.substr(i+1);			// Check whether rest substrings are equal.
                }
                else{                                               // Remove one char of "s".
                    // cout<<"Removing char: "<<endl;
                    s.erase(i,1);
                    return s.substr(i)==t.substr(i);				// Check whether rest substrings are equal.
                }
            }
        }
        return true;												// If mismatch occurs at last char of longest string, return true.	
    }
};