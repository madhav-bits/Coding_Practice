/*
*
//******************************************************111. Minimum Depth of Binary Tree.***********************************************

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


            
[3,9,20,4,5,null,7, null,8,null,null,10]

[3,9,20,4,5,null,7, null,8,9,null,10]

[]

[1,null,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. We try to reach nodes and start counting the height from there. When a node with one of child is NULL is 
// encountered, if we know which child is NULL, then our answer will depend on the answer on the result from the other child. If both child
// are not NULL, that node returns the min Height among the two results.
// If given tree is NULL, return 0.








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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;													// If node/given tree is NULL, return 0.
        if(root->left==NULL && root->right==NULL) return 1;							// If a leaf node is reached, return 1.
        
		// int lt= (root->left==NULL)?INT_MAX:minDepth(root->left);					// The commented lines indicate other method to solve prob.
        // int rt=(root->right==NULL)?INT_MAX:minDepth(root->right);				// If any of child is not NULL.
																					// If any of child is not NULL.
		if(root->left==NULL) return minDepth(root->right)+1;						// If left child is NULL, minDepth depends on right child.
        if(root->right==NULL) return minDepth(root->left)+1;						// If right child is NULL, minDepth depends on left child.
        return (min(minDepth(root->left), minDepth(root->right))+1);				// If both are not NULL, return min Height among them.
        
		//return min(lt, rt)+1;
    }
};