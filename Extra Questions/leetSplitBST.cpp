/*
*
//**************************************************************776. Split BST.*******************************************************

Given a Binary Search Tree (BST) with root node root, and a target value V, split the tree into two subtrees where one subtree has nodes that 
are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value.  It's not 
necessarily the case that the tree contains a node with value V.

Additionally, most of the structure of the original tree should remain.  Formally, for any child C with parent P in the original tree, if 
they are both in the same subtree after the split, then node C should still have the parent P.

You should output the root TreeNode of both subtrees after splitting, in any order.

Example 1:

Input: root = [4,2,6,1,3,5,7], V = 2
Output: [[2,1],[4,3,6,null,null,5,7]]
Explanation:
Note that root, output[0], and output[1] are TreeNode objects, not arrays.

The given tree [4,2,6,1,3,5,7] is represented by the following diagram:

          4
        /   \
      2      6
     / \    / \
    1   3  5   7

while the diagrams for the outputs are:

          4
        /   \
      3      6      and    2
            / \           /
           5   7         1
Note:

The size of the BST will not exceed 50.
The BST is always valid and each node's value is different.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,2,6,1,3,5,7]
2


[1,2,null,3,null,4,null,5]
3

[1,null,2,null,3,null,4,null,5]
4



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. In this algo. we separate the tree into two parts by traversing a path that divides it. At each step
// in the path, we differentiate the curr. node into either left or right subtree, if it goes into left subtree, we make it the right child of
// prev. left subtree's rightmost child. If not, we make the curr. node as left child of leftmost child of right subtree.






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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> v;												// Stores roots of left and right subtrees.
        TreeNode*lt,*rt;
        lt= new TreeNode(-1);												// Parent of root of left subtree.
        rt=new TreeNode(-1);
        TreeNode *ltDup= lt, *rtDup=rt;										// Dups of parents of root of right subtree.
        while(root){														// We traverse till end of tree.
            if(root->val>target){											// If curr. node is part of right subtree.
                rt->left=root;												// We make it left child of leftmost child of right subtree.
                rt=rt->left;
                root=root->left;											// Moving to next node, closer towards the target value.
            }
            else{															// If curr. node is part of left subtree.
                lt->right=root;												// We make it right child of rightmost child of left subtree.
                lt=lt->right;
                root=root->right;											// Moving to next node, closer towards the target value.
            }
        }
        lt->right=NULL;														// Making the last right child as NULL.
        rt->left=NULL;														// Making the last left child as NULL.
        v.push_back(ltDup->right);											// Pushing roots of subtrees into vector.
        v.push_back(rtDup->left);
        return v;															// Returning the roots of left and right subtrees.
    }
};

