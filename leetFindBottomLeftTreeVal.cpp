/*
*
//****************************************************513. Find Bottom Left Tree Value.*******************************************

Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.


//These are the examples I had created, tweaked and worked on.
[1,2,3,4,5,null,7,null,null,8]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algortihm does an Preorder traversal, saving the first encountered vaues in every level. Thus the last saved value is the Bottom Left
// Tree Value. This can also be done by Level Order Traversal using Queues.



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
    int value, maxm=INT_MIN;
    void findLeft(TreeNode* temp, int height){
        if(temp==NULL) return ;
        if(height>maxm){												//If this is the first time this level in entered, then value is stored.
            value=temp->val;
            maxm=height;												//Saving the max. level reached till now.
        }																// The last enocuntered fisrt value of a level is the Bottom Left Value.
        
        findLeft(temp->left, height+1);									// Pushing the left child into function call.
        findLeft(temp->right, height+1);								// Pushing the right child into function call.
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        findLeft(root,0);												// Pushing the root into the function call.
        return value;													// Returning the Botoom Left Value.
    }
};