/*
*
//******************************************************701. Insert into a Binary Search Tree.***********************************************

Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node 
of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4


*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,7,1,3]
5


[]
21


[20,10,30,5,15,25,35,3,7]
21




// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search Based. Here, we iterate through the tree to reach the leaf closest to the target value. Upon reaching the
// leaf. We create a new node with the target value. If the leaf's value<target value, then we make the new node, the right child of the leaf,
// if the leaf value>target value, then we make the new node the left child of the leaf node. Now, we return the root of the new modified BST.
// If the given tree is empty, we create a new node with target value and return it.








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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node=root;												// Temp. storing the root of the tree.
        if(!root) return new TreeNode(val);									// If empty tree is given, return the newly created Node.
        TreeNode *prev=NULL;												// Maintains the prev. visited node.
        while(root){	
            prev=root;														// Maintaining the curr. node in prev. node var. 
            if(root->val<val) root=root->right;								// If curr. node val<given val, then move to right child.
            else root=root->left;											// Else, move to left child.
        }
        if(prev->val<val) prev->right=new TreeNode(val);					// If the prev. node val<given val, we make new node it's right child.
        else prev->left=new TreeNode(val);									// Else, we make new node it's left child.
        return node;														// Return the root of the modified tree.
    }
};