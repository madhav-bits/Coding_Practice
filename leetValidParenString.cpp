/*
*
//******************************************************678. Valid Parenthesis String.***********************************************

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define 
the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"(()*****))"
"(**()(((()(((**)*())))"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm is Backtracking. We maintain the range of #'('s at any point of time. We make sure, that max. of range is >0, if not return
// false. We also maintain the low>=0, as values with <0, won't form a legal parenthesis(elimi. cases based on thiese values). At the end, the
// min. has to be 0, as min. is always maintained at >=0. If the min. is >0, then properly matched parenthesis are not formed(more '('s.

// A simple, observation, that #'('s will form a range of values, rather than non consecutive values. I missed this observation.
// I was looking to find out possibilities to decide on every "*" in the firt pass itself. 



class Solution {
public:
    bool checkValidString(string s) {
        int high=0, low=0;                          // Range of '('s in the string.
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){							// If '(' is encountered,then high and low are increased.
                high++;
                low++;
            }
            else if(s[i]==')'){						// If '(' is encountered,then high and low are decreased.
                high--;
                low--;
                if(high<0) return false;			// If, high is <0, then valid parenthesis can't be formed.
            }
            else{									// If '*' is encountered, the range increases.
                high++;								// Ex: The range [-1,1] will be extended to [-2,2]. -1->-2,-1,0 and 0->-1,0,1 and 1->0,1,2.
                low--;								// So, the range becomes [-2,2].
            }
            low=max(low,0);							// Eliminating, cases with #'('s <0. As, they are not valid parenthesis formation.
            
        }
        //cout<<"Low is: "<<low<<endl;
        //cout<<"High is: "<<high<<endl;
        return (low==0);							// For a valid parenthesis, low has to be 0, as min. is maintained to be >=0.
    }												// If min. >0, then #'('s are more than ')'s, so not valid.
};