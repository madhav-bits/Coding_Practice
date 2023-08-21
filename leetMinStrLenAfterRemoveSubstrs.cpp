/*
*
//**************************************2696. Minimum String Length After Removing Substrings.*****************************************

https://leetcode.com/problems/minimum-string-length-after-removing-substrings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ABFCACDB"
"ACBBD"
"CSGNACACACACSFGGMNDHBDBDJUCDCBDCDAAAHJBBADBACBCDABACDBACBDDFNGFMGYHMHDERG"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. We those chars in stack which are yet to be matched/paired to form 'AB' or 'CD', while iter. we check if curr. char and stack
// top form any of the two pairs, then we remove the stack top char else we add curr. char to stack hoping that this would form a pair with any of the rightside
// indices. We return the stack size at the end of iter., as it reflects the resulting str after removing all substrings.







class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char&ch:s) {
            if(ch=='D' && !st.empty() && st.top()=='C') st.pop();			// If stack top and curr. char form a 'AB' pair, we remove the stack top.
            else if(ch=='B' && !st.empty() && st.top()=='A') st.pop();		// If stack top and curr. char form a 'CD' pair, we remove the stack top.
            else st.push(ch);												// We add curr. char to stack hoping to pair with any later indices.
        }
        return st.size();													// Returning the length of the resulting string.
    }
};

