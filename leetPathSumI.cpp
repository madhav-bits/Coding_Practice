/*
*
//****************************************************************112. Path Sum.*******************************************************

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the 
given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,8,11,null,13,4,2,2,null,null,null,1]
26

[]
2

[5,4,8,11,null,13,4,2,2,null,null,null,1]
20




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is recursion based. To each child, we send a updated target sum(given target-curr. node val), if the curr. target sum becomes 0, 
// we check whether it's a leaf or not, if leaf return true. 





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
    bool hasPathSum(TreeNode* root, int sum) {
        //cout<<"Curr inside the fn. with node val: "<<root->val<< " and sum value: "<<sum<<endl;
        if(root==NULL) return false;												// If empty tree given ,return false.
        if(sum==root->val && !root->left && !root->right) return true;				// If leaf is reached and sum is obtained, return true.
        if(root->left!=NULL) 														// If left child exists, , call it with reduced target sum.
            if(hasPathSum(root->left, sum-root->val)) return true;
        if(root->right!=NULL) return hasPathSum(root->right, sum-root->val);		// If right child exists, call it with reduced target sum.
        return false;																// If sum not obtained is both child, then return false.
    }
};


