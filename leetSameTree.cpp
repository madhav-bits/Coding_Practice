/*
*
//**************************************************************100. Same Tree.*******************************************************

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,null,3]
[1,2,3]


[1,2,3,4,null,5]
[1,2,2,4,null,5]


[]
[]



[]
[0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. At each step, we check whether values of curr. node are equal or not? If not equal, return false else
// try checking in left and right child. Prior comparing values at curr. node, we check whether they are NULL or not?If both of them are NULL, 
// return true, if one of them is NULL, return false.





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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;											// If both are NULL, return true.
        if(p==NULL || q==NULL) return false;										// If only one is NULL, return false.
        if(p->val!=q->val) return false;											// If values are unequal, return false.
        return (isSameTree(p->left, q->left))?isSameTree(p->right, q->right):false;	// Now check in left and right child of both nodes.
    }
};

