/*
*
//******************************************************439. Ternary Expression Parser.***********************************************

Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the 
given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"F?2:T?F?0:1:12"


"T?T?F:5:3"


"T?F?T?1:2:3:4"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Once, we encounter "?" with "T", we focus on next set of chars, if it is followed by "?", then we push 
// it's following ones. IF we have "F" followed by "?", then we iterate till the count of "?",":"s match, we focus on next strs. IF we encounter
// ":" directly without any restraints, then that's the target value. 



class Solution {
public:
  string parseTernary(string s) {
  int begin=0;																// Stores the beginning of curr. str under consideration.
  for(int i=0;i<s.length();i++){
        // cout<<"The curr. index: "<<i<<endl;
        begin=i;															// Beginning of char under consid.
        while(i<s.length() && s[i]!='?' && s[i]!=':') i++;					// Iterate till we encount. "?"or ":".
        if(i<s.length() && s[i]=='?' && s[i-1]=='F'){						// If we have false encount.
            // cout<<"False encon."<<endl;
            i++;															// Inc. the index.
            int count=1;													// Inc. the count of signs(?=1, :=-1).
            while(count>0){													// While #"?"s are more than ":"s.
                // cout<<"Curr. scnning index: "<<i<<endl;
                if(s[i]=='?') count++;										// "?"s inc. the count.
                else if(s[i]==':') count--;									// ":"s inc. the count.
                i++;														// Inc. the iterator.
            }
            i--;
            // cout<<"Updated index: "<<i<<endl;
        }
        else if((i<s.length() && s[i]==':') || i==s.length()){				// If we encount. ":" directly, return char before it.
          return s.substr(begin,i-begin);
        }
      }
      return s.substr(begin,s.length()-begin);								// If last char is the result(":" won't follow it.).
    }
};