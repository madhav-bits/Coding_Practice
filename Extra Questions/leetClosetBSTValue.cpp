/*
*
//******************************************************270. Closest Binary Search Tree Value.***********************************************

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2147483647]
0.0

[8,4,null,null,5]
6

[8,4,null,null,5]
7

[8,4,null,null,5]
19



// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search Based. We search for the target value in given BST. In the process,we get min. dist from curr. node to target
// and return the node, which gives the min. diff.








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
    int closestValue(TreeNode* root, double target) {
        int res=root->val;													// Takes root as the default answer.
        while(root){														// Does Binary search in BST.
            if(abs(root->val-target)<abs(res-target)){						// If curr. is closest to target, save curr. node.
                res=root->val;
            }
            root=(root->val>target)?root->left:root->right;					// IF curr->val>target, we go to left child in search of closer vlaue
																			// to target, if not we go to right child in search of closet vaue.
        }
        
        return res;															// Return the node with closet value to target.
        
    }
};