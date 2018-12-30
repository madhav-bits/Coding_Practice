/*
*
//**********************************************************965. Univalued Binary Tree.***************************************************

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

 

Example 1:


Input: [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: [2,2,2,5,2]
Output: false
 

Note:

The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[2,2,2,2, 2,2,1,2]



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
// This algorithm is iteration based. Here, we start iterating from the root, we pass the value of root to left and right children, if we 
// enter in the recursion with NULL, we return true. If not NULL, we check the value of that node with passed value, if they are not equal, we
// return false, if equal we return the (&&)result of recursive calls given to left and right child.








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
    
    bool findRes(TreeNode* node, int temp){									// Checking whether curr. node and root value are equal or not.
        if(!node) return true;												// If curr. node is NULL, return true.
        if(node->val!=temp) return false;									// If curr. value!=root's value, return false.
        return findRes(node->left, node->val) && findRes(node->right, node->val);// Return (&&) of recursive calls to left, right child.
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;												// If empty tree given, return true.
        return findRes(root->left, root->val) && findRes(root->right, root->val);// Call to check Univalued Tree or not?
    }
};