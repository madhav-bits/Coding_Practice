/*
*
//******************************************************993. Cousins in Binary Tree.******************************************************

https://leetcode.com/problems/cousins-in-binary-tree/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,4]
4
3
[1,2,3,null,4,null,5]
5
4
[1,2,3,null,4]
2
3
[1,3,2,null,5,4]
3
2



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We check if the matchig nodes are siblings, if yes we return false. We store the mathcing level of the matching node, on reaching other matching node, we compare
// the level, if same we return true, else if the matching level is diff, we return false, else we set the matching level to curr. level. If curr. node isn't a matching node, we iter. in child tree
// in search of matching nodes.







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
    
    bool areCousins(TreeNode* root, int x, int y, int depth, int &matchDepth) {
        if(!root) return false;
        if(root->left && root->right) {																	// If both matching nodes are siblings,we return false.
            if(root->left->val<root->right->val && root->left->val==x && root->right->val==y) return false;
            if(root->right->val<root->left->val && root->right->val==x && root->left->val==y) return false;
        }
        if(root->val==x || root->val==y) {																// If curr. node is a matching node.
            if(matchDepth==depth) return true;															// If we already found a matching node(which isn't a sibling) and is of same level, return true.
            if(matchDepth!=-1) return false;															// If both matching nodes are of diff. level return false.
            matchDepth=depth;																			// Update the matching level to curr. level and skip searching in child as they would be of diff. level.
        }else {																							// Searching for matching nodes in child trees.
            if(areCousins(root->left, x, y, depth+1, matchDepth)) return true;							
            if(areCousins(root->right, x, y, depth+1, matchDepth)) return true;
        }
        return false;																					// Deafult return value.
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(x>y) return isCousins(root, y, x);
        int depth=0, matchDepth=-1;
        return areCousins(root, x, y, depth, matchDepth);												// DFS to find the matching nodes and check if they are cousins.
    }
};

