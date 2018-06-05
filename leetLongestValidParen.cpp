/*
*
//******************************************************32. Longest Valid Parentheses.***********************************************

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"((()(()))()("

"(()))))((((())()()()()()()()((((())))))))))((((("


"(()()"

"(()()"

"()(()()(()()(()())))"


""


"(()))))((((())()()()()))))()()()((((())))))))))((((("

"())))()((()()))((()()((()))))"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based(Can be done without stack also). Whenever an open paren encountered we push it directly into stack.
// When an closed paren encountered, we check for last unmatched paren in stack, if the last unamtched is an open parne., we count the dist. of
// that open paren. to curr. closed paren, we also add the max.len of consec. valid paren till the prev. index of last unmatched open paren. to it.
// We try to update the max. len of consec. valid paren. Thus, after the entire iteration, we get the max. len of consec. valid paren. 







class Solution {
public:
    int longestValidParentheses(string s) {
        int maxm=0;														// Stores max.len of consec. valid paren.
        vector<int> dp(s.length()+1,0);
        stack<int>st;													// Stores the unmatched parens.
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);									// If open paren encountered, push it.
            else{
                if(!st.empty() && s[st.top()]=='('){					// If closed paren. encountered and matching open paren. present.
                    // cout<<"New dp value at index: "<<i<<"is: "<<dp[st.top()]+i-st.top()+1<<"with dp top: "<<dp[st.top()]<<" and top index: "<<st.top()<<endl;
                    dp[i+1]=dp[st.top()]+i-st.top()+1;					// We calc. length from open to curr. closed paren.
                    // if(dp[i+1]>maxm){	
                    //     // cout<<"Max. is updated to: "<<dp[i+1]<<"and start index: "<<st.top()<<endl;
                    //     maxm=dp[i+1];
                    // }
                    maxm=max(maxm, dp[i+1]);							// Try to udpate the max.length of consecutive valid paren.
                    st.pop();											// Remove the curr. matched open paren.
                }
                else st.push(i);
            }
        }
        return maxm;													// Return the max. length consecutive valid paren.
    }
};