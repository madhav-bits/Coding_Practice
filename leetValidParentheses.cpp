/*
*
//**********************************************************20. Valid Parentheses.***************************************************

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"([{ }])"

"{[[[[((({{{}}})))]]]]}"

""

"[][[]"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based, at each step we check for opening braces, if it is we push it in stack, if not we try to match it's closing
// one on top of stack. If closing one is not found on stack, we return false. As, at any point of time, we ned to have >=opening braces than
// closing one, so, stack size has to be non-zero prior to scanning curr. closing braces.



class Solution {
public:
    bool isValid(string s) {
        if(s=="") return true;																			// As empty string is valid.
        int index=0;
        stack<string>st;																				// Tracks opening braces.
        while(index<s.length()){
            //cout<<"Curr. index is: "<<index<<" and string is: "<<s[index]<<"Empty: "<<st.empty()<<endl;
            if(s[index]== '{' || s[index]== '(' || s[index]== '[') st.push(s.substr(index,1));			// Storing opening braces.
            else if(st.empty()) return false;															// If non-opening and size==0->false
            else if( ((s[index]=='}' && st.top()=="{") || (s[index]==')' && st.top()=="(") || (s[index]==']' && st.top()=="["))) st.pop();  
            else return false;    																		// Matching closing braces.		
																										// Else return false.
            index++;																					// Moving iterator.
        }
        return (st.size()==0)?true:false;																// At end stack size have to be 0 for true.
    }
};