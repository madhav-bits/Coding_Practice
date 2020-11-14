/*
*
//********************************************1644. Lowest Common Ancestor of a Binary Tree II.*****************************************

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[3,5,1,6,2,0,8,null,null,7,4]
5
10



// Time Complexity: O(n).													// #nodes in the tree.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// #nodes in the tree.
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, the two nodes we are searching may not be in the tree. At every node, we gather we found
// the target nodes in it's subtrees. If we found target nodes in both subtrees, then curr. node is LCA. If we find target node in 
// one of subtrees and curr. node is also target node, we store curr. node as res. We return true from a node, if we find atleast 
// a target node in it's subtrees including itself.








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
    
    bool iterateTree(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &res){
        if(!node) return false;
        bool lt=iterateTree(node->left, p, q, res);							// Searching in left subtree.
        bool rt=iterateTree(node->right, p, q, res);
        if(lt && rt){														// If target nodes in both subtrees.
            res=node;														// Curr. node is LCA.
            return true;
        }
        bool match=(node==p|| node==q);										// If curr. node is one of target node.
        if(match && (lt || rt)){										// If curr. is target node and there is other in one of subtrees.
            res=node;
            return true;
        }
        return (match || lt||rt);											// If the subtree has atleast one target node.
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=NULL;
        iterateTree(root, p, q, res);										// Searches the tree for target nodes and LCA.
        return res;															// Returning the LCA of target nodes.
    }
};
