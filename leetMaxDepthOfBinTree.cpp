/*
*
//******************************************************104. Maximum Depth of Binary Tree.***********************************************

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1]
[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is recursion oriented. We extract the max. height from the child at each node. we forward the Max. Height of child+1 to the parent
// of the curr. node. At each first call, we obtain the max. Height of the entire tree.



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
    
    int calcHeight(TreeNode* root){
        if(root==NULL) return 0;														// In case of NULL, return 0.
        int maxm=INT_MIN;
        maxm=max(maxm, calcHeight(root->left));											// Extracting the left child Height.
        maxm=max(maxm, calcHeight(root->right));										// Extracting the right child Height.
        return 1+maxm;																	// Returning the Max. Child Height+1(Curr. Node).
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;														// If No tree present, return 0.
        return calcHeight(root);														// Return the Max. Height of the Tree.
    }
};