/*
*
//****************************************************1660. Correct a Binary Tree.***************************************************

https://leetcode.com/problems/correct-a-binary-tree/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provided with the question.
[1,2,3]
2
3
[8,3,1,7,null,9,4,2,null,null,null,5,6]
7
4



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, since a single node incorrectly links with a right side node at same level. We iterate tree
// where right subtree is visited first and all nodes are stored in a hash set. If a node's right node is already visited, means it is
// the right node to which curr. node is incorrectly linked. So, we replace curr. node with NULL and return the orig. tree.








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
    TreeNode* iterateTree(TreeNode* node, unordered_set<TreeNode*>&st){
        if(!node) return node;
        if(st.count(node->right)==1) return NULL;							// If right child is already visited(wrongly linked).
        st.insert(node);													// Marked curr. node as visited.
        node->right=iterateTree(node->right, st);							// Visit the right subtree.
        node->left=iterateTree(node->left, st);
        return node;														// Return the curr. node if curr. subtree is linked good.
    }
    
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*>st;											// Stores nodes which are linked.
        return iterateTree(root, st);										// Recur. call to iterate Tree and find wrong link.
    }
};