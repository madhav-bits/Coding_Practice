/*
*
//******************************************************572. Subtree of Another Tree.***********************************************

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A 
subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[3,4,5,1,2,null,null,1,null,null,null,1,null,3]
[4,1,2,3]



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is recursion based algo. At each step, we check whether values of nodes of both trees are equal or not. If equal, we call fn. 
// to check for left and right subtrees.






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
    bool same(TreeNode* s, TreeNode* t){											// This fn. checks for equality b/w these two subtrees.
        if(s==NULL && t==NULL) return true;											// If both nodes are NULL, return true.
        if(s==NULL || t==NULL) return false;										// If both are NULL, return false.
        if(s->val==t->val) return (same(s->left, t->left) && same(s->right, t->right));	// Once again as val. are eq., check in their child.
        return false;																// If curr. val/child are not equal return false.
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {										// This fn. tries all possible subtrees and compares to "t".
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        if(s->val==t->val){															// As curr. node val are equal, it checks similarity of subtrees
          if(same(s,t)) return true;  
        } 
        return (isSubtree(s->left, t) || isSubtree(s->right,t));					// Checks in left and right subtrees for similar subtrees to "t".
    }
};