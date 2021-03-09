/*
*
//**************************************************1190. Reverse Substrings Between Each Pair of Parentheses.*******************************************

https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/



You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
 

Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"(abcd)"
"(u(love)i)"
"(ed(et(oc))el)"
"a(bcdefghijkl(mno)p)q"
"ta()usw((((a))))"



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we store the strings enclosed in brackets in stack, whenever we encounter '(', we add the string gathered till then
// to prev. bracket(stack top), we have a default empty string for default bracket. When we encounter ')', we add string gathered till then to this bracket
// stack top and reverse the string, remove stack top and add it to prev. bracket(stack top), we thus have resulting string at top of stack by end of iter.










class Solution {
public:
    string reverseParentheses(string s) {
        string res="", temp="";
        
        stack<string>st;
        st.push("");
        bool flip=false;
        for(char ch:s){
            if(ch=='('){													// New bracket opens.
                st.top()+=temp;
                st.push("");
                temp="";
            }else if(ch==')'){												// Bracket closes, reverse the string gathered till then and add it prev. one.
                st.top()+=temp;
                temp=st.top();
                reverse(temp.begin(), temp.end());							// Reverse the string in this bracket.
                st.pop();
                st.top()+=temp;												// Add the string to prev. bracket.
                temp="";
                flip=!flip;
            }else temp+=ch;
        }
        st.top()+=temp;														// Add non-enclosed substr to default bracket.
        return st.top();													// Return the resulting string.
    }
};
