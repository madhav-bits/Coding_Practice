/*
*
//******************************************************124. Binary Tree Maximum Path Sum.***********************************************

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,-1,-2]


[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Similar to Longest Consecutive Nums in Tree. As path can start and end any where following parent-child relationship. It 
// can be a node with left,right child combined/ the largest of both/ or only a single node. Each node will return the longest sum path passing
// through that node( It can be-If the left/right child's sum is >0, then max of them+ node->val gives the max. value path or the node itself
// forms a max. sum path through that node). As complete path involving this node as turn in it, we try to include one/two child sum's+ curr. node
// value, try to update the overall max. sum var.








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
    
    int res=INT_MIN;														// Tracks max. path sum.
    
    int extractSum(TreeNode* node){
        if(!node) return 0;
        // cout<<"CUrr. node: "<<node->val<<endl;
        int leftSum=extractSum(node->left);									// Store the max. sum possible from left child.
        int rightSum=extractSum(node->right);								// Store the max. sum possible from right child.
        // cout<<"left child max: "<<leftSum<<endl;
        // cout<<"right child max: "<<rightSum<<endl;
        int maxChild=max(leftSum,rightSum);									// Maxsum among them.
        int ret=maxChild;
        ret=(maxChild>0)?maxChild+node->val:node->val;			// If max child's val>0, then we form max. path including that else only curr. node.
		int forward=ret;													
        ret=max(ret,leftSum+rightSum+node->val);							// Extracting the max. path with curr. node as turn.
        // cout<<"Max. at this node: "<<ret<<endl;
        res=max(res,ret);													// Try to update the overall max path sum.
        return forward;														// Returning the max. sum path through this node.
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;													// If empty tree given, return 0.
        extractSum(root);													// Call fn. to extract Max path Sum.
        return res;															// Returning the Max. Path Sum.
    }
};