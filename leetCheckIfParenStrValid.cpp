/*
*
//*********************************************2116. Check if a Parentheses String Can Be Valid.*********************************************

https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"))()))"
"010100"
"()()"
"0000"
")"
"0"
"()(()(()))(((())))"
"010010010100010010"
"()(()(()))(((())))"
"011010110100011010"
"())()))()(()(((())(()()))))((((()())(())"
"1011101100010001001011000000110010100101"
"(())))"
"000111"
"()))))))(((())))))"
"000011111110001110"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Stack based. Here, we try to balance the paren. and check whether they are balanced by iter. from two sides as the unlocked brackets can change their drns.
// We first iter. from left to right, where we count all unlocked, locked '(' brackets as open brackets and locked ')' as closed, we keep track of #open brackets, we inc. this 
//for open brackets and dec. this for closed brackets. If we come across a case where #open brackets<0, that means ')' are more than all available open. brackets to it's left,
// which leaves curr. bracket unbalanced and we can't balance it from right side brackets, so we return false, at the end of process we might have #open brackets>0, in this case
// half of them change their sides  and balance out rest of them. We repeat the same process but in reverse drn. If we dont' observe any issues in both drns, we return true.




// This discussion forum link has detailed explanation for this approach: 
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/discuss/1650613/Intuition-Explained-oror-Balanced-Parentheses-Greedy-Approach-oror-C%2B%2B-Clean-Code






class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0) return false;
        int open=0;
        for(int i=0;i<s.length();i++) {
            if(locked[i]=='0' || s[i]=='(') open++;							// All unlocked, locked and '(' are considered as open.
            else open--;													// Locked ')' are considered closed, so we open value.
            if(open<0) return false;										// If closed>open, we will have unbalanced ')'s, so we return false.
        }
        
																			// Same logic as above but in reverse direction.
        open=0;
        for(int i=s.length()-1;i>=0;i--) {
            if(locked[i]=='0' || s[i]==')') open--;
            else open++;
            if(open>0) return false;										// If open>closed, we will have unbalanced '('s, so we return false.
        }
        return true;														// Returning true as the string can be balanced.
    }
};

