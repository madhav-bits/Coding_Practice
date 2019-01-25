/*
*
//***********************************************************Longest valid Parentheses.*****************************************************

https://www.interviewbit.com/problems/longest-valid-parentheses/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


()()()(((()(())()()


(((((()))))((()()()()()


)()))(())((())))))())()(((((())())((()())(())((((())))())((()()))(()(((()()(()((()()))(())()))(((



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack and Dynamic Programming based. Here, we store in stack the indices of open parans('(') which are not balanced, so 
// when we encounter ')' we remove any open paran waiting to get balanced and pop it from stack. After balancing the unbalanced parans, then we 
// have last unbalanced open paran on top of stack, if we don't have one, it means closed parans are in excess, for which we maintain one more
// var last which says last excessive closed paran(we need this when stack is empty and looking to balance a new closed paran), in this case
// we get the dist. b/w this last unbalanced closed paran and curr. index and try to update the max. balanced paran length.








int Solution::longestValidParentheses(string s) {
    stack<int>st;															// Stores unbalanced open parans indices.
    int len=0, last=-1;														// Tracks max. balanced parans, last unbalanced closed paran.
    for(int i=0;i<s.length();i++){											// ITer. over all indices.
        if(s[i]=='(') st.push(i);											// Pushing closed parans into stack.
        else{
            if(!st.empty()) st.pop();										// If we have closed paran waiting to be balanced, remove it.
            else last=i;													// If no open paran, then update the last unbalanced closed paran index.
            if(st.empty()) len=max(len,i-last);								// Now, from unbalanced closed paran till curr. index are balanced.
            else len=max(len,i-st.top());									// Now, from last unbalanced open paran till curr. index are balanced.
        }
    }
    return len;																// Return the longest balanced paranthesis.
}
