/*
*
//*******************************************1372. Longest ZigZag Path in a Binary Tree.*******************************************

https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]



// Time Complexity: O(n).  													// n- #nodes in the tree.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- #nodes in the tree.
// Space Complexity: O(1).	
// This algorithm is DFS based. Every node gathers largest path with recent step being left, right from both child. We add left val. of 
// left child+1 and assign to right dist, similarly we add right val. of right child+1 and assign to left dist. Try to maximize the max. length
// If there is no node, we return {0,0}.






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
    
    pair<int,int> findLongestPath(TreeNode* node, int&res){
        if(node==NULL) return {0,0};										// In case of null node.
        pair<int,int>ans;
        ans.second=findLongestPath(node->left, res).first+1;				// Add recent left of left child+1, assign it to recent right.
        ans.first=findLongestPath(node->right, res).second+1;
        res=max({res, ans.first, ans.second});								// Update the maxm. len.
        return ans;															// Return the max. left, right recent turn len.
    }
    
    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;											// Base case.
        int res=0;
        findLongestPath(root, res);											// Func. call to calc. max len.
        return res-1;														// As, we need to return edges, we subtract one and return.
    }
};
