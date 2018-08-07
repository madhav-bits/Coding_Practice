/*
*
//******************************************************700. Search in a Binary Search Tree.***********************************************

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value.
 Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[]
1


[1]
1


[1]
2


[20,10,30,5,15,25,35,null,7,null,null,null,null,null,null,6]
7



[20,10,30,5,15,25,35,null,7,null,null,null,null,null,null,6]
6


[20,10,30,5,15,25,35,null,7,null,null,null,null,null,null,6]
35



[20,10,30,5,15,25,35,null,7,null,null,null,null,null,null,6]
10





// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search Based. We iterate through the BST for the target value, if that value exists in BST, we reach certainly, if 
// not we reach end of BST(A NULL node), we returned the last enocuntered node in the search(A node with target value if exists in tree/NULL
// node if value doesn't exist in tree).








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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res=NULL;													// Setting the returning var to default value.
        while(root){														// Iterating through BST.
            if(root->val==val) return root;									// If target value found, return that node.
            else if(root->val<val) root=root->right;						// If curr. val<target val, then the req. node might be in right child.
            else root=root->left;											// Else it might be in the left child.
        }
        return res;															// Returning NULL, in case value not found in BST.
    }
};