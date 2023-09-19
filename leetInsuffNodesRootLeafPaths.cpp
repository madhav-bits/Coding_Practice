/*
*
//********************************************1080. Insufficient Nodes in Root to Leaf Paths.*****************************************

https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]
1
[5,4,8,11,null,17,4,7,1,null,null,5,3]
22
[1,2,-3,-5,null,4,null]
-1




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. While iterating we keep track of sum of vals in the path, when we are at leaf, we return whether this path's total<limit
// if yes we return NULL inferring the parent to discard the child node else we return the curr. node to parent to retain. If both the child had returned NULL,
// it means all paths in both childs have a path with total<limit and we have to discard both child and since both children are discarded we have to remove 
// parent node also, so we return NULL to it's parent. If atleast one of the children has returned non-NULL, then there is atleast 1 path with total>=limit, 
// we can continue having curr. node and return curr. node to it's parent. We repeat the same process for all the nodes and return the node returned from 
// the call to the root of the tree.






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* removeInsufficientNodes(TreeNode* node, int limit, int total) {
        if(!node) return NULL;
        total+=node->val;
        if(!node->left && !node->right) {									// When we reached leaf node.
            return (total<limit)?NULL:node;									// We return NULL if total<limit else we return leaf node.
        }
        node->left=removeInsufficientNodes(node->left, limit, total);		// Assign child nodes based on the return values.
        node->right= removeInsufficientNodes(node->right, limit, total);
        if(!node->left && !node->right) return NULL;				// If both the child nodes are deleted(no path with total>limit), we req. del curr. node.
        return node;														// If there is a path with total>=limit, we return curr. node to cont. using it.
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // return (removeInsufficientNodes(root, limit, 0))?NULL:root;
        return removeInsufficientNodes(root, limit, 0);						// Call to remove insufficient nodes in the tree.
    }
};

