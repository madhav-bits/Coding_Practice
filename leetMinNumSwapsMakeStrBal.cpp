/*
*
//***************************************1963. Minimum Number of Swaps to Make the String Balanced.****************************************

https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"][]["
"]]][[["
"[]"
"]]][[["
"]]]][[[["
"][[]][]][][["



// Time Complexity: O(n).  													// The best Space Complexity is shown by the Second Solution.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we use stack to get the final state of the string when all the balanced brackets are cancelled out, the final state 
// would be in this pattern .....]]]]][[[[[[....., unbalanced group of closed brackets followed equal #unbalanced group of open brackets. We get their len,
// Swapping one pair of ],[s would balance out 4 of these unbalaned brackets in the best case and 2 unbalanced brackets in worst case. The best case is
// possible if we have >4 unbalanced chars, worst case if for <4 chars. So, calc. the #swaps accordingly and return it.








class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char&ch:s) {
            if(ch==']'){
                if(!st.empty() && st.top()=='[') st.pop();					// If unbalanced '[' present remove it.
                else st.push(ch);											// Else add ']' char to stack.
            } else st.push(ch);												// Adding '[' to stack with expectation to be balanced.
        }
        return (st.size()/4)+((st.size()%4)!=0);							// Returning the total #swaps required.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Stack+Observation based. Here, rather than stacks and getting the final state of unbalanced brackets, we use number to track the 
// #unbalanced open brackets and use (open+1)/2 to get required swaps value. When we encounter '[' we inc. the open value, else we dec. the open value only
// if there is unbalanced '[' present or open>0 because in case of open=0, which means curr. ']' bracket can't be balanced in string's curr. state and we
// ignore it, cause this bracket won't any affect on open brackets on it's right side and we are only tracking #open unbalanced brackets which would be equal
// to unbalanced ']' brackets anyways. We use (open+1)/2 for the reason explained in solution 1 to return #swaps required.







class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        for(char&ch:s) {
            if(ch=='[') open++;												// Inc. the count of unbalanced open brackets.
            else if(open>0) open--;											// Dec. open bracket count if any present.
        }
        return (open+1)/2;													// Returning the total #swaps required.
    }
};

