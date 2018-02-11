/*
*
//*****************************************************783. Minimum Distance Between BST Nodes.********************************************

Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[10,5,19,1,9,15,29,null, null, null, null,12]
[10,5,19,1,8,15,29,null, null, null, null,11]
[]




// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm does PreOrderTraversal and calculates the difference b/w consecutively visited nodes and stores the minm. of those differences.


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
    int minm=INT_MAX, curr=INT_MAX;								// Previously iterated node.
    void findMin(TreeNode* temp){
        //if(temp==NULL) return ;
        
        if(temp->left!=NULL) findMin(temp->left);				// Passing to the left child.
        minm=min(minm, abs(curr-temp->val));					// Comparing the prev. iterated node and curr. node.
        curr=temp->val;											// Updating the prev. visited node to the curr. node.
        if(temp->right!=NULL) findMin(temp->right);				// Passing to the right child.
        
    }
    
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return INT_MAX;							// If root is NULL, then INT_MAX has to be returned.
        findMin(root);
        return minm;											// Returning the minm. diff b/w nodes in the BST tree.
    }
};