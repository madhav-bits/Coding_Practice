/*
*
//**************************************************235. Lowest Common Ancestor of a Binary Search Tree.*******************************************

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T 
that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a 
descendant of itself according to the LCA definition.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

No option to provide custom test cases for this question.


// Time Complexity: O(n).
// Space Complexity: O(n).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).			
// It’s recursive and expands the meaning of the function. 
// We calculate, whether both values are to the left/ right of the curr. node, the node where the target values are on both side of curr. node is 
// the res. node. We also return the curr. node if it's value equals one of the two values, as the second value would be in it's subtree in BST.


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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root->val == p->val || root->val == q->val ) return root;	// IF matched. one of target values.
        int minm=min(p->val, q->val);											// Calc. the min of two target values.
        int maxm=max(p->val, q->val);
        TreeNode* res;
        if(root->val>maxm)														// The two target values are to left of curr. node.
            res=lowestCommonAncestor(root->left, p, q);
        else if(root->val<minm)													// The two target values are to right of curr. node.
            res=lowestCommonAncestor(root->right, p, q);
        else																	// The two target values are on both sides of curr. node. So,
            return root;														// we return the curr. node.
        return res;																// Return the value from left/right calls if possible.
        
    }
};