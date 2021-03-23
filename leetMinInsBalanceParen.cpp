
/*
*
//********************************************1541. Minimum Insertions to Balance a Parentheses String.***********************************************

https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/


Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as openning parenthesis and '))' as closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

 

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to to add one more ')' at the end of the 
string to be "(())))" which is balanced.
Example 2:

Input: s = "())"
Output: 0
Explanation: The string is already balanced.
Example 3:

Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
Example 4:

Input: s = "(((((("
Output: 12
Explanation: Add 12 ')' to balance the string.
Example 5:

Input: s = ")))))))"
Output: 5
Explanation: Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".
 

Constraints:

1 <= s.length <= 10^5
s consists of '(' and ')' only.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


"(()))"
"())"
"))())("
"(((((("
 ")))))))"
"(()))(()))()())))"
"()()))"
"(()))(()))()())))"
"()()()))"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. As consecutive "))" would match "(". For every occurance of ')', we check it's adj. char, if it's ')',
// and if we have '(' ahead we match open with these both ')', if not we add another ')' to result. If we encounter '(', we inc. open count.
// Diff. cases of '(' and ')' are clearly explained in the comments, written aside code.







class Solution {
public:
    int minInsertions(string s) {
        
        int open=0, close=0, res=0;											// res- #insertions made till that point of iteration.
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){													// If '(' encountered, we inc. the open count.
                open++;
            }else{
                if(i+1<s.length() && s[i+1]==')'){							// If next char is ')'.
                    if(open>0) open--;										// If open '(' exists, we match it with curr. ')' char.
                    else res++;												// If not open exists, we insert it and remove these two ')' chars.
                    i++;
                }else{														// If next char isn't ')'.
                    if(open>0) res++, open--;								// If open exists, we insert ')' char and remove curr. ')' and open '('.
                    else res+=2;											// If no open '(' exists, we insert '(' and ')' and remove this "())"
                }
            }
        }
        return res+2*open;													// We return total insertions required, 2*open- as open need to be matched.
    }
};

