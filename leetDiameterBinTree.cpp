/*
*
//******************************************************543. Diameter of Binary Tree.***********************************************

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the 
longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,5,null,null,6,null,7,8,9,null,10,null,11,null,null,12,null,13,null,14,15]
[]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based, we need to calculate the max depth of left and right childs, and add them and check whether they form max
// depth or not. Also, assign/return max. depth of the curr. node.





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
    int maxm=INT_MIN;
    int calcDist(TreeNode* root){
        if(root==NULL) return 0;													// If NULL node, return 0 Depth.
        
        int lDist=calcDist(root->left);												// Calc. Max Depth in the left child.
        int rDist=calcDist(root->right);											// Calc. Max Depth in the right child.
        maxm=max(maxm, lDist+rDist);												// Update the Max. Depth variable.
        return max(lDist, rDist)+1;													// Update the depth of the curr. node.
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;													// If empty tree, return 0.
        calcDist(root);																// Calling fn. to cald. diameter.
        return maxm;																// Returning diameter.
    }
};