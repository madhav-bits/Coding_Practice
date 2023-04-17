/*
*
//******************************************************2641. Cousins in Binary Tree II.******************************************************

https://leetcode.com/problems/cousins-in-binary-tree-ii/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,9,1,10,null,7]
[3,1,2]
[1,2,3,4,null,null,5,6,null,7,8,9,10,null,11]



// Time Complexity: O(n).  																				// n-#nodes in the tree.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).																				// n-#nodes in the tree.
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we first iterate to store the sum of values in each level. Next, we iter. and update the values of both child from the parent node, we recursively update
// the values from bottom to top levels.







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
    
    void iterateTree(TreeNode* node, vector<int>&v, int depth) {										// Iterate the tree to collect sum of nodes at each level.
        if(!node) return ;
        if(v.size()==depth) v.push_back(0);
        v[depth]+=node->val;
        iterateTree(node->left, v, depth+1);
        iterateTree(node->right, v, depth+1);
        return ; 
    }
    
    
    void updateTree(TreeNode* node, vector<int>&v, int depth) {											// Iterate the tree to update values of each node.
        if(!node) return ;	
        if(!node->left && !node->right) return ;														// Terminating condition for leaves.
        
        updateTree(node->left, v, depth+1);																// Update values of children's children first(i.e bottom to top levels)
        updateTree(node->right, v, depth+1);
        
        
        int val=0;
        if(node->left) val+=node->left->val;															// Gathering total of children.
        if(node->right) val+=node->right->val;
        
        if(node->left) node->left->val=v[depth+1]-val;													// Updating the values of children of current node.
        if(node->right) node->right->val=v[depth+1]-val;
        
        return ;
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>levelSum;
        iterateTree(root, levelSum, 0);																	// DFS to collect sum of nodes of each level.
        
        root->val=0;
        updateTree(root, levelSum, 0);																	// DFS to update values as per given requirements.
        return root;																					// Returning the tree with updated values.
    }
};

