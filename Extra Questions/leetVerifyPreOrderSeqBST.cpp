/*
*
//**************************************************255. Verify Preorder Sequence in Binary Search Tree.*******************************************

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,2,6,1,3]


[5,2,6,1,3,9]


[]


[4,3,2,1]


[1,2,3,4]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we store the values in stack, for which we are looking for right child. Whenever you encounter a greater
// value, that's the right child for the top of stack, we pop it, while popping we store the min. value of node popped, so that all further elem.
// encountered has to be greater than min. value var. As, the right node for this popped elem. is encount. all further values have to be greater
// than popped elem. If we encounter any values <min. value, return false. If, we reach end of iter. without any issues, then return true.








class Solution {
public:
    bool verifyPreorder(vector<int>& v) {
        if(v.size()==0) return true;										// If empty tree given, return true.
        stack<int>st;														// Stores nodes for which we are looking for right child.
        int minm=INT_MIN;													// Tracks min. value that the curr. index's value can have.
        for(int i=0;i<v.size();i++){										// Iter. through the array.
            if(v[i]<minm) return false;										// If curr. value is <min. value allowed, then return false.
            while(!st.empty() && st.top()<v[i]){							// Popping all nodes for which are left of curr. value.
                minm=st.top();												// Updating the min. value.
                st.pop();													// Popping the top of stack.
            } 
            st.push(v[i]);													// Push the curr. value into stack(Looking for left, right child).
        }
        return true;														// No issues encount. return true.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*************************************************THIS SOLUTION IS FOR FOLLOW UP CHALLENGE.*******************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algo. is Divide and Conquer based. For the values under a node, we assign min. and max. value assigned, if the root is not in that range
// we return false. We iter. through array till we encounter a value> curr. node value, to find the left, right child parts. We recursively give
// calls to verify left and right child(Whether those values are in limits or not). Left child's range min. of curr. range to curr. node, range
// of right child to curr. node to max. of curr. range. Whenever we receive false from child, we return false. Else, return true.


class Solution {
public:
    
    bool verify(vector<int>&v,int start,int end, int minm, int maxm){		// Verifies preOrder seq. from start,end indices.
        if(start>end) return true;											// If no node exists, return true.
        if(v[start]<minm || v[start]>maxm) return false;					// If curr. node value isn't in limits, return false.
        int ind=start+1;													// Init. the iter. to find start of right child.
        while(ind<=end && v[ind]<v[start]) ind++;							// Iter. until a val>curr. node is found(right child).
        bool lt=verify(v,start+1,ind-1,minm,v[start]);						// Calling fn. to verify left child.
        if(!lt) return false;												// If false, return false.
        bool rt=verify(v,ind,end,v[start],maxm);							// Calling fn. to verify right child.
        return rt;															// Return returned value from right child.
    }
    
    bool verifyPreorder(vector<int>& v) {
        if(v.size()==0) return true;										// If empty tree given return true.
        return verify(v,0,v.size()-1,INT_MIN, INT_MAX);						// Calling fn. to verify preOrder Sequence.				
    }
};