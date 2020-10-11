/*
*
//***********************************1614. Maximum Nesting Depth of the Parentheses.***************************************

https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/





*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked with the cases provided with the question.
"(1+(2*3)+((8)/4))+1"
"(1)+((2))+(((3)))"
"1+(2*3)/(2-1)"
"1"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, the given str is balanced. So, we just have to count, #open parens encountered
// at every moment. Curr. at an instant indicates the depth of parens we are in. Encountering ")" indicates that we are 
// out of paren. We try to maximize the curr. open paren count and track and return it.






class Solution {
public:
    int maxDepth(string s) {
        int res=0, currDepth=0;
        for(auto ch:s){
            if(ch=='('){													// Entering into paren.
                currDepth++;
                res=max(res, currDepth);									// Maximizing the depth we are in.
            } 
            else if(ch==')') currDepth--;									//  Coming out of paren.
        }
        return res;
    }
};