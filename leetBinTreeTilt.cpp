/*
*
//**********************************************************563. Binary Tree Tilt.***************************************************

Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right 
subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,5]
[1,2,3, 4,12,null,4]
[]
[1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. At each step, we extract the sum of values in both the childs, then we get their abs diff. and add it to a 
// global variable. We also add both child's extracted sum and curr. node's value and return the sum to the parent of curr. node.
// Thus, we calcualte tilt of entire tree, which we will return at the end.






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum=0;																	// Global variable to track entire tree's tilt.
    int calcTilt(TreeNode* node){
        int lt=0, rt=0;
        if(node->left!=NULL) lt=calcTilt(node->left);							// Extr. left child's nodes vlaues sum.
        if(node->right!=NULL) rt=calcTilt(node->right);							// Extr. right child's nodes vlaues sum.
        sum+=abs(lt-rt);														// Calc. the tilt of that node.
        return node->val+lt+rt;													// Returning this node's self and child nodes values sum.
    }
    
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;												// If Empty tree given, return 0.
        calcTilt(root);															// Calling fn. to extract tree's tilt. 
        return sum;																// Return the Entire tree's tilt value.
    }
};