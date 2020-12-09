/*
*
//********************************************1676. Lowest Common Ancestor of a Binary Tree IV.****************************************

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.

Worked on test cases provide with question.
[3,5,1,6,2,0,8,null,null,7,4]
[4,7]
[3,5,1,6,2,0,8,null,null,7,4]
[1]
[3,5,1,6,2,0,8,null,null,7,4]
[7,6,2,4]
[3,5,1,6,2,0,8,null,null,7,4]
[0,1,2,3,4,5,6,7,8]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is DFS based. Here, we approach as if all target nodes may not present in the tree. So, when returning form every
// node we return the #matches we obtained in this subtree. So, for every match we check whether #matches total target nodes and res
// node is NULL, we update res node. We gather #matches in left and right subtree, if the total is =target #nodes, we update res with 
// curr. node.







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
    
    int iterateTree(TreeNode* node, unordered_set<TreeNode*>&st, TreeNode* &res){
        if(node==NULL) return 0;    										// Base case.
        int match=(st.count(node));
        if(match==st.size() && !res){										// If #matches =target#nodes, update res.
            res=node;
            return match;
        }
        match+=iterateTree(node->left, st, res);							// Iterate left subtree.
        if(match==st.size() && !res){
            res=node;
            return match;
        }
        match+=iterateTree(node->right, st, res);							// Iterate right subtree.
        if(match==st.size() && !res) res=node;
        return match;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size()==0) return root;
        unordered_set<TreeNode*>st;
        for(TreeNode* node: nodes) st.insert(node);							// Pushing target nodes into map.
        TreeNode* res=NULL;
        iterateTree(root, st, res);											// Iterate the Tree.
        return res;															// Return the Lowest Common Ancestor node.
    }
};