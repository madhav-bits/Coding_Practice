/*
*
//******************************1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree.******************************

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[7,4,3,null,null,6,19]
3


[8,null,6,null,5,null,4,null,3,null,2,null,1]
4



// Time Complexity: O(n).													
// Space Complexity: O(1).													// n- total #nodes in the tree.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													
// Space Complexity: O(1).													// n- total #nodes in the tree.
// This algorithm is iteration based. Here, we iter. over both the trees parallely, whenever we found target node in orig. tree, we 
// return the curr. node from the duplicate tree iter. 







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
    
    TreeNode* iterateTree(TreeNode* node1, TreeNode* node2, TreeNode* target){	// Iter. parallelly on both trees.
        if(node1==NULL) return NULL;
        if(node1==target) return node2;										// If target node found, dup's curr. node is returned.
        TreeNode* lt=iterateTree(node1->left, node2->left, target);
        if(lt) return lt;													// If left subtree has ans, we return ans from the child.
        return iterateTree(node1->right, node2->right, target);				// If left don't have ans, we return right child's response.
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return iterateTree(original, cloned, target);						// Func. call to start iter. on two trees parallelly.
    }
};
