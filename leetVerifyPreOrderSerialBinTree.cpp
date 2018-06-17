/*
*
//**************************************************331. Verify Preorder Serialization of a Binary Tree.*******************************************

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a 
null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an 
algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"#,#"


"1,#,#"

"1,#"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array. As, each node in the Tree has to be visited twice, I maintain a stack keeping track, number of nodes
// curr. node's ancestors are visited. If we visit a node, we push -2 into stack, stating it expects to be visited twice, upon getting visited
// twice, we pop that value from the stack. If "#" encountered, we inc. it's parent's(top of stack) count. If at any point we encounter an 
// empty stack, aprat from the end of string, then the child doesn't have any parent, that's not legal. At the end of iteration, if we have an
// empty stack, then it's valid tree.








class Solution {
public:
    bool isValidSerialization(string s) {
        int index=0;
        stack<int>st;														// Keeps track of encountered node's count.
        while(index<s.length() && s[index]!=',') index++;
        if(s.substr(0,index)!="#") st.push(-2);								// If the root is not null(#), then push -2 into stack.
        index++;
        while(index<s.length()){											// Iterating till the end of the array.
            // cout<<"Curr. index: "<<index<<endl;
            int prev;
            if(!st.empty()){												// Extracting top value.
                prev=st.top();
                st.pop();
                if(prev!=-1)												// Inc. the count and pushing back into stack.
                    st.push(prev+1);
            }
            else return false;												// If stack is empty, return false.
            int old=index;													// Curr. index.
            while(index<s.length() && s[index]!=',') index++;				// Extract string(value/#).
            index++;														// Moving the iterator to next value/#.
            if(s.substr(old,index-old-1)=="#") continue;  					// If extracted str is "#", then don't push into stack.
            st.push(-2);													// Push -2, representing curr. node into stack.
        }
        // cout<<"stack size: "<<st.size()<<endl;
        
        return st.empty();													// If stack is empty, it's valid Tree.
    }
};