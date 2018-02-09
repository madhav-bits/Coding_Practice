/*
*
//****************************************************129. Sum Root to Leaf Numbers.*******************************************

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.


//These are the examples I had created, tweaked and worked on.
[1,2,3,4,5,null,6,null, null,8,null,9]
[1,2,3,4,5,null,7,null,null,8]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This is iteating in Inorder traversal. By calc. sum of values from root till that node and passing it to the child, which returns the
// accumulated sum because of that child's leaf nodes, we add accu. sum because of two childs(if exist) and pass it to it's parent node. Thus
// we get the required Sum Root to Leaf.



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
    int findSum(TreeNode* temp, int nodeVal){
        if(temp==NULL) return 0;												// Can also be done without modifying node values,just pass-
        temp->val+=(nodeVal*10);												//- the accumulated sum till then directly without saving in var.
        if(temp->left==NULL && temp->right==NULL ){								// Updating the node val, needed to be passed to child.
            return temp->val;													// If this a leaf, then return sum because of that leaf.
        }
        return findSum(temp->left,temp->val)+findSum(temp->right, temp->val);	//Sum accumulated because of the node's leaves.
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return findSum(root,0);													// Returns the sum, because of this node's children's leaves.
    }
};