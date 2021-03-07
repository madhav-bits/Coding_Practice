/*
*
//******************************************************1110. Delete Nodes And Return Forest.***********************************************


https://leetcode.com/problems/delete-nodes-and-return-forest/


Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[1,2,3,4,5,6,7]
[3,5]
[1,2,4,null,3]
[3]
[40,20,60,10,30,50,70,5,15,25,35,45,55,null,75]
[10,25,40,60]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is DFS based. Here, at every node if it is one of delete nodes and it's children are not children nodes, then we check children to 
// final result. If the children are one of the delete nodes, then we replace the children with NULL.











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
    
    void iterateTree(TreeNode* node, vector<bool>&delValues, vector<TreeNode*>&res){
        if(!node) return ;
        if(delValues[node->val] && node->left && delValues[node->left->val]==false)// If node. is DelNode and children are not, add children to list.
            res.push_back(node->left);
        if(delValues[node->val] && node->right && delValues[node->right->val]==false)
            res.push_back(node->right);
        
        
        iterateTree(node->left, delValues, res);
        iterateTree(node->right, delValues, res);
        
        if(node->left && delValues[node->left->val]) node->left=NULL;		// If children are delete node, then make children as NULL.
        if(node->right && delValues[node->right->val]) node->right=NULL;
        
        return ;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;
        if(!root) return res;
        vector<bool>delValues(1001,false);									
        for(int num:to_delete) delValues[num]=true;							// Store delete values in array for quick access.
        if(delValues[root->val]==false) res.push_back(root);				// If root is not delete node, add it to final list.
        iterateTree(root, delValues, res);									// Iterate Tree for finding forest root nodes.
        return res;															// Returning the roots of remaining forests.
    }
};

