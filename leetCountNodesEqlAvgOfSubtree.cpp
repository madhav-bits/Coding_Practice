/*
*
//********************************************2265. Count Nodes Equal to Average of Subtree.**********************************************

https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,8,5,0,1,null,6]
[1]
[5,4,7,6,5,8,7,6,3,6,7,9,10,14,12,15,14,32,2,5,7,4,2,6,4,2,34]
[5,7,6,8,9,4,5,6,7,8,4,6,7,8,4,3,9]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. While iterating over the tree, we collect sum of nodes in the left, right child of each node first and we get theese values 
// from DFS calls to left, right child. We check if avg of nodes in left, right child, curr. node is equal to curr. node, if yes we inc. res by 1. We return 
// sum of all nodes in subtree and nodes count to parent node of curr. node, we repeat the same process for all the nodes and return res at the end of iter.







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
    
    pair<int,int> calculateAvg(TreeNode* node, int& res) {
        if(!node) return {0,0};
        pair<int, int>lt=calculateAvg(node->left, res);						// Get sum of nodes, #nodes in left child.
        pair<int,int>rt=calculateAvg(node->right, res);						// Get sum of nodes, #nodes in right child.
        lt.first+=rt.first+node->val;										// Adding values of all nodes in left, right child and curr. node.
        lt.second+=rt.second+1;												// Adding #nodes in left, right child and curr. node(1).
        if(node->val==lt.first/lt.second) res++;							// Checking if avg. of curr. subtree eqls curr. node.
        return lt;															// Returning sum of all nodes in curr. subtree, #nodes in curr. subtree to parent.
    }
    
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        calculateAvg(root, res);											// Calling DFS on curr. tree.
        return res;															// Returning #nodes whose val eqls avg. of the subtree rooted at that node.
    }
};

